//
// Created by Cedric Plouvier on 2019-04-22.
//

#ifndef CARGAME_SDLENEMYCAR_H
#define CARGAME_SDLENEMYCAR_H

#include <SDL.h>
#include <SDL_image.h>

#include "EnemyCar.h"

class SDLEnemyCar : public EnemyCar {
public:
    SDLEnemyCar(SDL_Renderer* r);
    virtual ~SDLEnemyCar();
    bool vis (int level);
private:
    SDL_Surface* enemyCarBackground;
    SDL_Renderer* renderer;
    SDL_Texture* enemyCarTexture;
};


#endif //CARGAME_SDLENEMYCAR_H
