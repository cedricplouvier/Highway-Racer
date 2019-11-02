//
// Created by Cedric Plouvier on 2019-03-04.
//

#include "Game.h"

Game::~Game() {
}
//The game constructor stores the Factory as its private factory.
Game:: Game(Afact* Fact){
    F = Fact;
}

// start() is the first function to be called when the application starts from main.
// It initialises all game parametes with the init() method.
// Once the game is initialised the gameloop is started with gameLoop().
 void Game :: start() {
     init();
     menu -> startMenu();
     gameLoop();
 }

// init() initialises game parameters and creates all objects needed during the game loop.
void Game :: init (){
    // As long as running is true the game is running.
    running = true;
    // The speed the enemies come at you (in pixels per loop of 16 ms).
    enemySpeed = 6;
    // The amount of enemies that have spawn.
    spawnCount =1;
    // Amount of times the gameloop has been iterated.
    loopCounter=0;
    // Amount by which the enemy speed increases (pixels per gameloop) after each wave of ennemies.
    enemySpeedIncrease = 3;

    // Creating of all the needed objects for the application through our abstract factory
    menu = F -> createMenu();
    player = F -> createPlayer();
    highWay = F -> createHighWay();
    powerUpAmmo = F -> createPowerUpAmmo();
    powerUpCoin = F -> createPowerUpCoin();
    C = F->createCar();
    bullet = F -> createBullet();
    eventHandler = F -> createEventHandler();
    for(int i =0; i < amountOfEnemyCars; i++){
        ECCars[i] = F -> createEnemyCar();
    }
}
// Loop that gets iterated while the player is playing.
// It is important that all visualization methods vis() remain in the same order.
// highWay has to be visualized first because its vis() clears the renderer.
// C has to be visualized as last because its vis() has renders everything that has been copied in the renderer.
void Game :: gameLoop(){

    const int FPS = 60;
    // FrameDelay is the amount of milisecond every iteration of gameloop has to take to achieve 60 FPS.
    const int frameDelay = 1000/FPS;
    // The time at which the frame starts gets stored in frameStart.
    uint32_t frameStart;
    int frameTime;

    while(running) {
        frameStart = SDL_GetTicks();
        loopCounter +=1;
        highWay -> vis();
        powerUpAmmo -> vis();
        powerUpCoin -> vis();
        // Checks all input of the user.
        eventHandler -> pollEvent(C,bullet,player);
        // If statement that checks is the player has quit. When quit the while loop won't be iterated again
        if(player -> getQuit()){
            running=false;
            cout << "QUIT" << endl;
        }
        // When the player has paused the game keep polling for only one event (unpause), neglecting all other user input.
        while(player -> paused){
            eventHandler -> pollEventPause(player);
        }
        // When the gameLoop is iterated a multiple of 80 times, a new enemy car starts getting visualized.
        // The enemy car only gets visualized if it alive, meaning it is not hit by a players car bullet.
        if(loopCounter >= (80)*spawnCount) {
            for (int i = 0; i < spawnCount; i++) {
                if (ECCars[i] -> alive) {
                    ECCars[i]->vis(enemySpeed);
                }
            }
            if (loopCounter == (80)*(spawnCount+1) && spawnCount < amountOfEnemyCars) {
                spawnCount += 1;
            }
            // Check the position of the last EnemyCar of the array(-1 since the array starts at 0).
            // If its y position is above 90 the last enemycar has passed the screen and a new wave can start
            // by resetting all enemycars position (random) and making all enemy cars alive again.
            // Powerups gets respawned at a new random position (at a negative y) for the next wave.
            // The player score gets updated by the amound of enemy cars in the wave and the speed of the enemy cars gets increased.
            pair<int,int> lastCarPos = ECCars[amountOfEnemyCars-1] -> getPos();
            if(lastCarPos.second > 900){
                for(int i=0; i<amountOfEnemyCars;i++){
                    ECCars[i] -> resetPosition();
                    ECCars[i] -> alive = true;
                }
                spawnPowerUp();
                loopCounter =0;
                spawnCount = 1;
                player -> upScore(amountOfEnemyCars);
                enemySpeed += enemySpeedIncrease;
            }
        }
        bullet->vis();
        player -> showScore();
        C->vis();
        // If the is a collision the player car and the enemy car or the player car is out of boundaries the gameOver()
        // method gets called and once progressed from this method the player restarts the game (by reinitialising).
        if(collisionDetection()){
            cout << "collision detected" << endl;
            died = true;
            gameOver();
            start();
        }
        // Check for collision between player car and powerups.
        powerUpCollisionDetection();
        // Check for collision between bullet and enemy cars.
        bulletCollisionDetection();
        // Calculate how long the loop has taken and wait till the loop takes 16 miliseconds
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    // The if statement is a bug fix. If we leave it out and we play 2 or more times in one session the gameQuit();
    // function gets called twice (probable because of nested loops. Giving an exit code 11 because we want to delete
    // object in gameQuit() that have alreade been deleted.
    if(!died) {
        gameQuit();
    }
}

// Resets the position of the powerups
void Game :: spawnPowerUp(){
    powerUpAmmo -> resetPowerUpPos();
    powerUpCoin -> resetPowerUpPos();
}
// Checks for collision between the player car and all enemy cars
 bool Game :: collisionDetection(){
    for(int i=0; i< spawnCount;i++) {
        pair<int, int> carPos = C->getPos();
        pair<int, int> enemyCarPos = ECCars[i] ->getPos();

        int leftCarPos = carPos.first;
        int rightCarPos = carPos.first + C->carWidth;
        int topCarPos = carPos.second;
        int bottomCarPos = carPos.second + C->carLength;

        int leftEnemyCarPos = enemyCarPos.first;
        int rightEnemyCarPos = enemyCarPos.first + C->carWidth;
        int topEnemyCarPos = enemyCarPos.second;
        int bottomEnemyCarPos = enemyCarPos.second + C->carLength;

        if (topCarPos <= bottomCarPos && bottomCarPos >= topEnemyCarPos && rightCarPos > leftEnemyCarPos &&
                leftCarPos < rightEnemyCarPos && topCarPos < bottomEnemyCarPos) {
                return true;
        } else if (leftCarPos < 50 || rightCarPos > 590 || carPos.second > (Afact::SCREEN_HEIGHT- EnemyCar::enemyCarLength) || topCarPos < 0 + Player::topBarHeight) {
                return true;
            }
    }
    return false;
}
// Check for collision of the bullet with all the enemy cars.
// When a buller hits the enemy the players increases his score by one. The collided enemy car is not alive anymore.
// The bullet gets positioned outside of our vision. It stays there untill the player shoots again.
bool Game :: bulletCollisionDetection(){
    for(int i=0; i<spawnCount;i++){
        pair<int,int> bulletPos = bullet -> getPos();
        pair<int, int> enemyCarPos = ECCars[i] ->getPos();

        int leftBulletPos = bulletPos.first;
        int rightBulletPos = bulletPos.first + bullet -> bulletWidth;
        int topBulletPos = bulletPos.second;
        int bottomBulletPos = bulletPos.second + bullet -> bulletHeight;

        int leftEnemyCarPos = enemyCarPos.first;
        int rightEnemyCarPos = enemyCarPos.first + C->carWidth;
        int topEnemyCarPos = enemyCarPos.second;
        int bottomEnemyCarPos = enemyCarPos.second + C->carLength;

        if (topBulletPos <= bottomBulletPos && bottomBulletPos >= topEnemyCarPos && rightBulletPos > leftEnemyCarPos &&
            leftBulletPos < rightEnemyCarPos && topBulletPos < bottomEnemyCarPos) {
            ECCars[i] -> alive = false;
            ECCars[i] -> setPosition(0,F -> SCREEN_HEIGHT + 100);
            bullet -> setPosition(-100,-100);
            player -> upScore(1);
            return true;
        }
    }
    return false;
}
// Chech for collision detection of the player car with the different power ups.
bool Game ::powerUpCollisionDetection() {
    pair<int, int> carPos = C -> getPos();
    pair<int, int> powerUpPosAmmo = powerUpAmmo -> getPos();
    pair<int, int> powerUpPosCoin = powerUpCoin -> getPos();

    int leftCarPos = carPos.first;
    int rightCarPos = carPos.first + C->carWidth;
    int topCarPos = carPos.second;
    int bottomCarPos = carPos.second + C->carLength;

    int leftPowerUpPosAmmo = powerUpPosAmmo.first;
    int rightPowerUpPosAmmo = powerUpPosAmmo.first + powerUpAmmo->powerUpWidth;
    int topPowerUpPosAmmo = powerUpPosAmmo.second;
    int bottomPowerUpPosAmmo = powerUpPosAmmo.second + powerUpAmmo->powerUpLength;

    int leftPowerUpPosCoin = powerUpPosCoin.first;
    int rightPowerUpPosCoin = powerUpPosCoin.first + powerUpAmmo->powerUpWidth;
    int topPowerUpPosCoin = powerUpPosCoin.second;
    int bottomPowerUpPosCoin = powerUpPosCoin.second + powerUpAmmo->powerUpLength;

    if (topCarPos <= bottomCarPos && bottomCarPos >= topPowerUpPosAmmo && rightCarPos > leftPowerUpPosAmmo &&
        leftCarPos < rightPowerUpPosAmmo && topCarPos < bottomPowerUpPosAmmo) {
        powerUpAmmo -> setPosition(0,1000);
        cout << "collision with ammo" << endl;
        player -> amountOfAmmo =5;
        return true;
    }else if(topCarPos <= bottomCarPos && bottomCarPos >= topPowerUpPosCoin && rightCarPos > leftPowerUpPosCoin &&
             leftCarPos < rightPowerUpPosCoin && topCarPos < bottomPowerUpPosCoin){
        powerUpCoin -> setPosition(0,1000);
        cout << "collision with coin" << endl;
        player -> upScore(coinValue);
        return true;
    }
}

// A Cleanup function that deletes all objects (and corresponding SDL_Textures of their respective SDL_object).
// This is done to prevent memory leaks when we keep restarting the game.
void Game ::gameOver() {

    delete C;
    delete highWay;
    delete player;
    delete bullet;
    delete powerUpAmmo;
    delete powerUpCoin;
    for(int i=0; i< amountOfEnemyCars; i++){
        delete ECCars[i];
    }
    menu -> gameOver();
    delete menu;
    delete eventHandler;
}
// A Cleanup function identical to the gameOver() cleanup function with the adition that also the Abstract factory
// gets deleted and therefor also the window and renderer
void Game ::gameQuit(){
    cout << "gameQuit" << endl;
    delete C;
    delete highWay;
    delete player;
    delete bullet;
    delete powerUpAmmo;
    delete powerUpCoin;
    for(int i=0; i< amountOfEnemyCars; i++){
        delete ECCars[i];
    }
    delete menu;
    delete eventHandler;
    delete F;
}


