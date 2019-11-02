//
// Created by Cedric Plouvier on 2019-03-18.
//

#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H

#include <utility>
#include "Entity.h"

using namespace std;

class Car : public Entity {
public:
    Car();
    virtual ~Car();
    virtual bool vis()=0;

    static const int carWidth = 100;
    static const int carLength = 150;
};


#endif //CARGAME_CAR_H
