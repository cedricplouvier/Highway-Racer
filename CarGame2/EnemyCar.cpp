//
// Created by Cedric Plouvier on 2019-04-22.
//

#include "EnemyCar.h"

// The constructor immediatly determines a random lane for the enemy car
EnemyCar::EnemyCar() {
    alive = true;
    // A random lane number between 1 and 4 is chosen.
    int randNum = (rand() % 4) + 1;
    switch (randNum){
        case 1 :
            Entity :: setPosition(70,-200);
            break;
        case 2 :
            Entity :: setPosition(200,-200);
            break;
        case 3 :
            Entity :: setPosition(330,-200);
            break;
        case 4 :
            Entity :: setPosition(460,-200);
            break;
    }
}

EnemyCar::~EnemyCar() {}

bool EnemyCar ::vis(int level) {
    return 0;
}
// This function is to respawn the enemy cars with a random lane.
void EnemyCar ::resetPosition() {
    int randNum = (rand() % 4) + 1;
    switch (randNum){
        case 1:
            setPosition(70,-200);
            break;
        case 2:
            setPosition(200,-200);
            break;
        case 3:
            setPosition(330,-200);
            break;
        case 4:
            setPosition(460,-200);
            break;
    }
}