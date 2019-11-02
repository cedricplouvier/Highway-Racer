//
// Created by Cedric Plouvier on 2019-03-23.
//

#ifndef CARGAME_SDLCAR_H
#define CARGAME_SDLCAR_H

#include <SDL.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <SDL_image.h>
#include <stdint.h>
#include <iostream>


#include "Car.h"

class SDLcar : public Car {
public:
    SDLcar(SDL_Renderer* r);
    virtual ~SDLcar();
    bool vis();
private:
    SDL_Renderer* renderer;
    SDL_Texture* carTexture;
    SDL_Surface* carBackground;
};


#endif //CARGAME_SDLCAR_H
