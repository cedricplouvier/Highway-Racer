//
// Created by Cedric Plouvier on 2019-06-16.
//

#ifndef CARGAME_SDLPOWERUPCOIN_H
#define CARGAME_SDLPOWERUPCOIN_H

#include <iostream>
#include <SDL_image.h>
#include "PowerUpCoin.h"

class SDLPowerUpCoin : public PowerUpCoin {
public:
    SDLPowerUpCoin(SDL_Renderer* r);

    virtual ~SDLPowerUpCoin();
    bool vis();
private:
    SDL_Renderer* renderer;
    SDL_Texture* coinTexture;

};


#endif //CARGAME_SDLPOWERUPCOIN_H
