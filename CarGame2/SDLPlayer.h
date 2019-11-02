//
// Created by Cedric Plouvier on 2019-04-26.
//

#ifndef CARGAME_SDLPLAYER_H
#define CARGAME_SDLPLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;


#include "Player.h"

class SDLPlayer : public Player {
public:
    SDLPlayer(SDL_Renderer* r);
    virtual ~SDLPlayer();
    void showScore();


private:
    SDL_Renderer* renderer;
    SDL_Surface* topBar;
    SDL_Texture* topBarTexture;
    SDL_Surface* scoreSurface;
    SDL_Texture* scoreTexture;
    SDL_Surface* bulletSurface;
    SDL_Texture* bulletTexture;
    TTF_Font * font;
    // The color for the string to be represented in RGB values.
    SDL_Color textColor = {0,0,0};

};


#endif //CARGAME_SDLPLAYER_H
