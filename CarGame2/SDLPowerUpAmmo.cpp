//
// Created by Cedric Plouvier on 2019-06-16.
//

#include "SDLPowerUpAmmo.h"

// Contructor loads the renderer pointer into its own render pointer private field.
// Afterwards it creates a texture using the renderer and a surface from an image.
SDLPowerUpAmmo::SDLPowerUpAmmo(SDL_Renderer* r) {
    renderer = r;
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface* ammoBackground= IMG_Load("../Images/ammo.png");
    ammoTexture = SDL_CreateTextureFromSurface(renderer,ammoBackground);
    SDL_FreeSurface(ammoBackground);
}

// Destroy the texture when the corresponding object gets deleted
SDLPowerUpAmmo::~SDLPowerUpAmmo() {
    SDL_DestroyTexture(ammoTexture);
}

// Copy the Texture at the correct location into the renderer.
// The location of the powerup gets changed at every visualization with the powerUpSpeed set in powerUps.h
bool  SDLPowerUpAmmo :: vis (){

    SDL_Rect ammoPosition;
    ammoPosition.h = powerUpLength;
    ammoPosition.w = powerUpWidth;
    ammoPosition.x = position.first;
    ammoPosition.y = position.second;

    updatePosition(0,powerUpSpeed);

    SDL_RenderCopy(renderer, ammoTexture, NULL, &ammoPosition);

    return 0;
}
