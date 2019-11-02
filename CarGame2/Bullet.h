//
// Created by Cedric Plouvier on 2019-06-15.
//

#ifndef CARGAME_BULLET_H
#define CARGAME_BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet();

    virtual ~Bullet();
    virtual bool vis ()=0;

    static const int bulletWidth = 20;
    static const int bulletHeight = 30;
};


#endif //CARGAME_BULLET_H
