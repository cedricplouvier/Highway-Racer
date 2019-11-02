//
// Created by Cedric Plouvier on 2019-06-15.
//
#ifndef CARGAME_EVENTHANDLER_H
#define CARGAME_EVENTHANDLER_H

#include <SDL.h>
#include <iostream>
#include "Car.h"
#include "Bullet.h"
#include "Entity.h"
#include "Player.h"

using namespace std;

class EventHandler {
public:
    EventHandler();
    virtual ~EventHandler();

    virtual void pollEvent(Car* C, Bullet* b, Player* p);
    virtual void pollEventPause(Player* p);
    void eventUp(Car* C);
    void eventDown(Car* C);
    void eventLeft(Car* C);
    void eventRight(Car* C);
    void eventLeftUp(Car* C);
    void eventRightUp(Car* C);
    void eventSpace(Car* C, Bullet* b, Player* p);
    void eventQuit(Player* p);
    void eventPause(Player* p);

};


#endif //CARGAME_EVENTHANDLER_H
