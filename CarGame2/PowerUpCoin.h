//
// Created by Cedric Plouvier on 2019-06-16.
//

#ifndef CARGAME_POWERUPCOIN_H
#define CARGAME_POWERUPCOIN_H

#include "PowerUps.h"


class PowerUpCoin : public PowerUps {
public:
    PowerUpCoin();
    virtual ~PowerUpCoin();
    virtual bool vis();
};


#endif //CARGAME_POWERUPCOIN_H
