//
// Created by Cedric Plouvier on 2019-03-25.
//

#include "SDLHighWay.h"

using namespace std;

// Contructor loads the renderer pointer into its own render pointer private field.
// Afterwards it creates a texture using the renderer and a surface from an image.
SDLHighWay::SDLHighWay(SDL_Renderer* r){
    renderer = r;
    highWayBackground = SDL_LoadBMP( "../Images/HighWay22.bmp" );
    highWayTexture = SDL_CreateTextureFromSurface(renderer, highWayBackground);
    SDL_FreeSurface(highWayBackground);
}

// Destroy the texture when the corresponding object gets deleted
SDLHighWay::~SDLHighWay() {
    SDL_DestroyTexture(highWayTexture);
}

// Copy the Texture at the correct location into the renderer.
// Since highway is the first object to be visualised it clears the renderer from previous gameloop.
// When the highway rolls down it remaining 1800 pixels from its start position it is put back at its start position.
bool SDLHighWay :: vis(){
    SDL_Rect backgroundPos;
    backgroundPos.h = highway_height;
    backgroundPos.w = highway_width;
    backgroundPos.x = highWayPosX;
    backgroundPos.y = highWayPosY;

    SDL_RenderClear(renderer);
    highWayPosY += 5;
    if (highWayPosY== 0){
        highWayPosY =-1800;
    }
    SDL_RenderCopy(renderer, highWayTexture, NULL, &backgroundPos );
    return 0;
}
