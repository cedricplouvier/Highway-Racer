//
// Created by Cedric Plouvier on 2019-06-16.
//

#include "PowerUps.h"

// Contructor for all powerups that determines a random lane between 1 and 4 and a random negative y coordinate
// between 1 and 900.
PowerUps::PowerUps() {
    int randNum = (rand() % 4) + 1;
    int randHeight = -((rand() % 900) + 1);
    switch (randNum){
        case 1 :
            Entity :: setPosition(110,randHeight);
            break;
        case 2 :
            Entity :: setPosition(240,randHeight);
            break;
        case 3 :
            Entity :: setPosition(370,randHeight);
            break;
        case 4 :
            Entity :: setPosition(500,randHeight);
            break;
    }
}

PowerUps::~PowerUps() {}
bool PowerUps :: vis(){}

// Method to reset the powerups at a random location like in the constructor for the next wave of enemies.
void PowerUps :: resetPowerUpPos() {
    int randNum = (rand() % 4) + 1;
    int randHeight = -((rand() % 900) + 1);
    switch (randNum){
        case 1 :
            Entity :: setPosition(110,randHeight);
            break;
        case 2 :
            Entity :: setPosition(240,randHeight);
            break;
        case 3 :
            Entity :: setPosition(370,randHeight);
            break;
        case 4 :
            Entity :: setPosition(500,randHeight);
            break;
    }
}


