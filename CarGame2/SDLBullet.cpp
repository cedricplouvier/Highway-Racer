//
// Created by Cedric Plouvier on 2019-06-15.
//

#include "SDLBullet.h"

// Contructor loads the renderer pointer into its own render pointer private field.
// Afterwards it creates a texture using the renderer and a surface from an image.
SDLBullet::SDLBullet(SDL_Renderer* r) {
    renderer = r;
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface* bulletBackground= IMG_Load("../Images/bulletcut.png");
    bulletTexture = SDL_CreateTextureFromSurface(r, bulletBackground);
    SDL_FreeSurface(bulletBackground);
}

// Destroy the texture when the corresponding object gets deleted
SDLBullet::~SDLBullet() {
    SDL_DestroyTexture(bulletTexture);
}

// Copy the Texture at the correct location into the renderer.
bool SDLBullet ::  vis(){
    SDL_Rect bulletPosition;
    bulletPosition.h = bulletHeight;
    bulletPosition.w = bulletWidth;
    bulletPosition.x = position.first;
    bulletPosition.y = position.second;

    Entity :: updatePosition(0,-10);

    SDL_RenderCopy( renderer, bulletTexture, NULL, &bulletPosition );

    return 0;
}
