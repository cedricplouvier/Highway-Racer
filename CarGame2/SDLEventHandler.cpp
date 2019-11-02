//
// Created by Cedric Plouvier on 2019-06-15.
//

#include "SDLEventHandler.h"

SDLEventHandler::SDLEventHandler() {}

SDLEventHandler::~SDLEventHandler() {}

// Method that gets called every gameloop to check to players input en give it to the eventHandler.
void SDLEventHandler :: pollEvent(Car* C, Bullet* b, Player* p) {
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    SDL_Event event;
    while(SDL_PollEvent(&event)!=0){
        if( event.type == SDL_QUIT )
        {
            EventHandler :: eventQuit(p);
        }
        else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_SPACE :
                    EventHandler :: eventSpace(C,b,p);
                    break;
                case SDLK_p :
                    EventHandler :: eventPause(p);
                    break;
            }
        }
    }
    if (keyState[SDL_SCANCODE_UP] && keyState[SDL_SCANCODE_RIGHT]){
        EventHandler :: eventRightUp(C);
    }
    else if (keyState[SDL_SCANCODE_UP] && keyState[SDL_SCANCODE_LEFT]){
        EventHandler :: eventLeftUp(C);
    }
    else if (keyState[SDL_SCANCODE_UP]) {
        EventHandler :: eventUp(C);
    }
    else if (keyState[SDL_SCANCODE_LEFT]){
        EventHandler :: eventLeft(C);
    }
    else if (keyState[SDL_SCANCODE_RIGHT]){
        EventHandler :: eventRight(C);
    }
    else if (keyState[SDL_SCANCODE_DOWN]){
        EventHandler :: eventDown(C);
    }

}
// Method that gets called while the game is paused to only check if the player hits 'p' to unpause or quits the game.
// It then get processed by the eventhandler
void SDLEventHandler ::  pollEventPause(Player* p){
    SDL_Event event;
    while(SDL_PollEvent(&event)!=0){
        if( event.type == SDL_QUIT )
        {
            EventHandler :: eventQuit(p);
        }
        else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_p :
                    EventHandler :: eventPause(p);
                    break;
            }
        }
    }
}