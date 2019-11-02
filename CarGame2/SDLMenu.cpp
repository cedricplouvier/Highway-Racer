//
// Created by Cedric Plouvier on 2019-04-25.
//

#include "SDLMenu.h"

// Contructor loads the renderer pointer into its own render pointer private field.
SDLMenu::SDLMenu(SDL_Renderer* r) {
    renderer = r;
}

// Destroy the texture when the corresponding object gets deleted
SDLMenu::~SDLMenu() {
    SDL_DestroyTexture(startTexture);
    SDL_DestroyTexture(gameOverTexture);
}

// Method that gets called at the start of the game before the gameloop starts.
// It stays in this menu untill the player hits space
// It would be better practice to handle the loop that waits for input by the eventHandler
bool SDLMenu ::startMenu() {
    startBackground = SDL_LoadBMP( "../Images/start.bmp" );
    startTexture = SDL_CreateTextureFromSurface(renderer, startBackground);

    SDL_FreeSurface(startBackground);

    bool running = true;
    SDL_Event event;
    while (running) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_SPACE :
                        running = false;
                        break;
                }
            }
        }

        SDL_RenderCopy( renderer, startTexture, NULL, NULL );
        SDL_RenderPresent( renderer );
    }

    SDL_DestroyTexture(startTexture);
    return 0;
}

// Method gets called after a collision of the player car with an enemy car or if its out of its boundaries.
// It stays in this menu untill the player mouseclick into the boundaries of the defined rectangle.
// It would be better practice to handle the loop that waits for input by the eventHandler
void SDLMenu :: gameOver(){

    SDL_Rect buttonAgain;
    buttonAgain.x=175;
    buttonAgain.y = 770;
    buttonAgain.w= 290;
    buttonAgain.h =85;

    gameOverBackground= IMG_Load ("../Images/gameOver.png");
    gameOverTexture = SDL_CreateTextureFromSurface(renderer, gameOverBackground);

    SDL_FreeSurface(gameOverBackground);

    bool running = true;
    SDL_Event event;
    while (running){
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_MOUSEBUTTONUP){
                int x,y;
                SDL_GetMouseState(&x, &y);
                if(x > buttonAgain.x && x < (buttonAgain.x + buttonAgain.w) && y > buttonAgain.y && y < (buttonAgain.y + buttonAgain.h)){
                    running = false;
                }
            }
        }

        SDL_RenderCopy(renderer, gameOverTexture,NULL,NULL);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(gameOverTexture);
}
