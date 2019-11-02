//
// Created by Cedric Plouvier on 2019-03-23.
//

#include "SDLcar.h"


using namespace std;

// Contructor loads the renderer pointer into its own render pointer private field.
// Afterwards it creates a texture using the renderer and a surface from an image.
SDLcar::SDLcar(SDL_Renderer* r) {
    renderer = r;
    IMG_Init(IMG_INIT_PNG);
    carBackground = IMG_Load("../Images/yellowCar2.png");
    carTexture = SDL_CreateTextureFromSurface(r, carBackground);
    SDL_FreeSurface(carBackground);

}
// Destroy the texture when the corresponding object gets deleted
SDLcar::~SDLcar() {
    SDL_DestroyTexture(carTexture);
}

// Copy the Texture at the correct location into the renderer.
// Since this is also the last object to be copied into te renderer it renders the renderer with SDL_RenderPresent.
bool SDLcar :: vis() {
    SDL_Rect carPosition;
    carPosition.h = carLength;
    carPosition.w = carWidth;
    carPosition.x = position.first;
    carPosition.y = position.second;

    SDL_RenderCopy( renderer, carTexture, NULL, &carPosition );
    SDL_RenderPresent( renderer );

    return 0;
}


