//
// Created by Cedric Plouvier on 2019-06-16.
//

#ifndef CARGAME_SDLPOWERUPAMMO_H
#define CARGAME_SDLPOWERUPAMMO_H

#include <iostream>
#include <SDL_image.h>
#include "PowerUpAmmo.h"


class SDLPowerUpAmmo : public PowerUpAmmo {
public:
    SDLPowerUpAmmo(SDL_Renderer* r);
    virtual ~SDLPowerUpAmmo();
    bool vis();
private:
    SDL_Renderer* renderer;
    SDL_Texture* ammoTexture;
};


#endif //CARGAME_SDLPOWERUPAMMO_H
