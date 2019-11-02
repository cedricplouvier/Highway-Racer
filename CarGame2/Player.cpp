//
// Created by Cedric Plouvier on 2019-04-26.
//

#include "Player.h"

Player::Player() {
    score = 0;
    amountOfAmmo=5;
    quit = false;
    paused = false;
}
Player::~Player() {}
// Method to increment the players score
void Player :: upScore(int s){
    score += s;
}
void Player :: showScore(){}
void Player :: setQuit(){
    quit = true;
}
// Method to check if the player has quit
bool Player :: getQuit(){
    return quit;
}
// Method that toggles the state of the paused variable to pause/unpause
void Player :: togglePause(){
    if(paused){
        paused = false;
    }
    else if(!paused){
        paused=true;
    }
}


