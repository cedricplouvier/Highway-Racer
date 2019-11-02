//
// Created by Cedric Plouvier on 2019-06-15.
//

#ifndef CARGAME_SDLEVENTHANDLER_H
#define CARGAME_SDLEVENTHANDLER_H

#include "EventHandler.h"
#include <iostream>

using namespace std;

class SDLEventHandler : public EventHandler {
public:
    SDLEventHandler();
    virtual ~SDLEventHandler();
    void pollEvent(Car* C, Bullet* b, Player* p);
    void pollEventPause(Player* p);

};


#endif //CARGAME_SDLEVENTHANDLER_H
