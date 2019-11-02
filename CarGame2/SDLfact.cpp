//
// Created by Cedric Plouvier on 2019-03-04.
//

#include <iostream>
#include "SDLfact.h"

using namespace std;

// Contructor that initialises the window and renderer for all our object to be visualized on
SDLfact::SDLfact() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    window = SDL_CreateWindow( "Best Cargame ever", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
}

// Destroy the window and the renderer only when the game gets quit
SDLfact::~SDLfact() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    cout << "renderer and window destroyed" << endl;
}


SDLcar* SDLfact :: createCar(){
    return new SDLcar(renderer);
}

SDLHighWay* SDLfact :: createHighWay(){
    return new SDLHighWay(renderer);
}

SDLEnemyCar* SDLfact ::createEnemyCar() {
    return new SDLEnemyCar(renderer);
}

SDLMenu* SDLfact :: createMenu(){
    return new SDLMenu(renderer);
}
SDLPlayer* SDLfact :: createPlayer(){
    return new SDLPlayer(renderer);
}
Bullet* SDLfact :: createBullet(){
    return new SDLBullet(renderer);
}

EventHandler* SDLfact ::createEventHandler() {
    return new SDLEventHandler();
}

PowerUpAmmo* SDLfact :: createPowerUpAmmo(){
    return new SDLPowerUpAmmo(renderer);
}

PowerUpCoin* SDLfact ::createPowerUpCoin() {
    return new SDLPowerUpCoin(renderer);
}