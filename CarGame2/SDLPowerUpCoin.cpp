//
// Created by Cedric Plouvier on 2019-06-16.
//

#include "SDLPowerUpCoin.h"

// Contructor loads the renderer pointer into its own render pointer private field.
// Afterwards it creates a texture using the renderer and a surface from an image.
SDLPowerUpCoin::SDLPowerUpCoin(SDL_Renderer* r) {
    renderer = r;
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface* coinBackground= IMG_Load("../Images/coin.png");
    coinTexture = SDL_CreateTextureFromSurface(renderer,coinBackground);
    SDL_FreeSurface(coinBackground);
}

// Destroy the texture when the corresponding object gets deleted
SDLPowerUpCoin::~SDLPowerUpCoin() {
    SDL_DestroyTexture(coinTexture);
}

// Copy the Texture at the correct location into the renderer.
// The location of the powerup gets changed at every visualization with the powerUpSpeed set in powerUps.h
bool SDLPowerUpCoin :: vis(){

    SDL_Rect coinPosition;
    coinPosition.h = powerUpLength;
    coinPosition.w = powerUpWidth;
    coinPosition.x = position.first;
    coinPosition.y = position.second;

    updatePosition(0,powerUpSpeed);

    SDL_RenderCopy(renderer, coinTexture, NULL, &coinPosition);

    return 0;
}


