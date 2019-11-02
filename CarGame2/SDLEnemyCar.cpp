//
// Created by Cedric Plouvier on 2019-04-22.
//

#include "SDLEnemyCar.h"

// Contructor loads the renderer pointer into its own render pointer private field.
// Afterwards it creates a texture using the renderer and a surface from an image.
SDLEnemyCar::SDLEnemyCar(SDL_Renderer* r) {
    renderer = r;
    IMG_Init(IMG_INIT_PNG);
    enemyCarBackground= IMG_Load("../Images/EnemyCopCar2.png");
    enemyCarTexture = SDL_CreateTextureFromSurface(r, enemyCarBackground);
    SDL_FreeSurface(enemyCarBackground);
}

// Destroy the texture when the corresponding object gets deleted
SDLEnemyCar::~SDLEnemyCar() {
    SDL_DestroyTexture(enemyCarTexture);
}

// Copy the Texture at the correct location into the renderer.
// The enemy car position gets changed its speed everytime is gets visualized before copied into the renderer.
// The enemy car must only be copied into the renderer if it hasn't yet passed out screen (y location < 900)
bool SDLEnemyCar :: vis(int enemySpeed){

    SDL_Rect enemyCarPosition;
    enemyCarPosition.h = enemyCarLength;
    enemyCarPosition.w = enemyCarWidth;
    enemyCarPosition.x = position.first;
    enemyCarPosition.y = position.second;

    Entity :: updatePosition(0,enemySpeed);

    if(enemyCarPosition.y < 900) {
        SDL_RenderCopy(renderer, enemyCarTexture, NULL, &enemyCarPosition);
    }
    return 0;
}
