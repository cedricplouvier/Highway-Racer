//
// Created by Cedric Plouvier on 2019-06-15.
//

#ifndef CARGAME_SDLBULLET_H
#define CARGAME_SDLBULLET_H

#include <SDL_image.h>
#include "Bullet.h"
#include <iostream>

using namespace std;

class SDLBullet : public Bullet{
public:
    SDLBullet(SDL_Renderer* r);
    virtual ~SDLBullet();
    bool vis();
private:
    SDL_Renderer* renderer;
    SDL_Texture* bulletTexture;
};


#endif //CARGAME_SDLBULLET_H
