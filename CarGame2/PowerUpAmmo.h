//
// Created by Cedric Plouvier on 2019-06-16.
//

#ifndef CARGAME_POWERUPAMMO_H
#define CARGAME_POWERUPAMMO_H

#include <iostream>
#include "PowerUps.h"

class PowerUpAmmo : public PowerUps {
public:
    PowerUpAmmo();
    virtual ~PowerUpAmmo();
    virtual bool vis();
};


#endif //CARGAME_POWERUPAMMO_H
