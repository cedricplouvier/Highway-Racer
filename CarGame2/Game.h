//
// Created by Cedric Plouvier on 2019-03-04.
//

#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H

#include <cstdlib>      //include for random generation of number
#include <ctime>        //needed for random generation
#include <random>
#include <iostream>
#include <vector>
#include <random>
#include <SDL.h>

#include "Afact.h"
#include "Menu.h"

using namespace std;

class Game {
public:
    Game(Afact* Fact);
    virtual ~Game();
    void start();

private:
    int spawnCount;
    int loopCounter;
    int enemySpeed;
    int enemySpeedIncrease;
    bool running;
    bool died = false;
    static const int amountOfEnemyCars = 5;
    static const int coinValue=5;

    Afact* F;
    Car* C;
    HighWay* highWay;
    Bullet* bullet;
    PowerUpAmmo* powerUpAmmo;
    PowerUpCoin* powerUpCoin;
    Menu* menu;
    Player* player;
    EventHandler* eventHandler;
    EnemyCar* ECCars[amountOfEnemyCars];

    void init();
    bool collisionDetection();
    void gameOver();
    void gameLoop();
    void gameQuit();
    bool bulletCollisionDetection();
    bool powerUpCollisionDetection();
    void spawnPowerUp();
};


#endif //CARGAME_GAME_H
