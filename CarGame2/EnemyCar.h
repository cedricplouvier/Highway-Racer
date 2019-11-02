//
// Created by Cedric Plouvier on 2019-04-22.
//

#ifndef CARGAME_ENEMYCAR_H
#define CARGAME_ENEMYCAR_H

#include <cstdlib>      //include for random generation of number
#include <ctime>        //needed for random generation
#include <random>
#include <iostream>

#include "Entity.h"

class EnemyCar : public Entity {
public:
    EnemyCar();
    virtual ~EnemyCar();

    virtual bool vis (int level)=0;
    void resetPosition();

    static const int enemyCarWidth = 100;
    static const int enemyCarLength = 150;
    bool alive;

};


#endif //CARGAME_ENEMYCAR_H
