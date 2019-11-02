//
// Created by Cedric Plouvier on 2019-04-25.
//

#ifndef CARGAME_SDLMENU_H
#define CARGAME_SDLMENU_H

#include <SDL.h>
#include <SDL_image.h>

#include "Menu.h"


class SDLMenu : public Menu{
public:
    SDLMenu(SDL_Renderer* r);
    virtual ~SDLMenu();
    bool startMenu();
    void gameOver();

private:
    SDL_Renderer* renderer;
    SDL_Texture* startTexture;
    SDL_Texture* gameOverTexture;
    SDL_Surface* startBackground;
    SDL_Surface* gameOverBackground;
};


#endif //CARGAME_SDLMENU_H
