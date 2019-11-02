//
// Created by Cedric Plouvier on 2019-03-25.
//

#ifndef CARGAME_SDLHIGHWAY_H
#define CARGAME_SDLHIGHWAY_H

#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include "HighWay.h"



using namespace std;

class SDLHighWay: public HighWay {
public:
    SDLHighWay(SDL_Renderer* r);
    virtual ~SDLHighWay();
    bool vis();
private:
    SDL_Renderer* renderer;
    SDL_Surface* highWayBackground;
    SDL_Texture* highWayTexture;
};


#endif //CARGAME_SDLHIGHWAY_H
