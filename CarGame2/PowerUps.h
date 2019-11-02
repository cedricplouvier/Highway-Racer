//
// Created by Cedric Plouvier on 2019-06-16.
//

#ifndef CARGAME_POWERUPS_H
#define CARGAME_POWERUPS_H

#include "Entity.h"
#include <iostream>

class PowerUps : public Entity {
public:
    PowerUps();
    void resetPowerUpPos();
    virtual ~PowerUps();
    virtual bool vis();

    static const int powerUpLength = 30;
    static const int powerUpWidth = 30;
    // Speed at which the power ups move. Best effect when speed is matched with speed of the highWay
    static const int powerUpSpeed = 5;
};


#endif //CARGAME_POWERUPS_H
