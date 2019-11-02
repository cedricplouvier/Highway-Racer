//
// Created by Cedric Plouvier on 2019-04-26.
//

#include "SDLPlayer.h"

// Contructor loads the renderer pointer into its own render pointer private field.
// Afterwards it creates a texture using the renderer and a surface from an image.
SDLPlayer::SDLPlayer(SDL_Renderer* r) {
    renderer = r;
    IMG_Init(IMG_INIT_JPG);
    topBar = IMG_Load("../Images/topBar.png");
    topBarTexture = SDL_CreateTextureFromSurface(r, topBar);
    SDL_FreeSurface(topBar);
}
// Destroy the texture when the corresponding object gets deleted
SDLPlayer::~SDLPlayer() {
    SDL_DestroyTexture(topBarTexture);
    SDL_DestroyTexture(scoreTexture);
    SDL_DestroyTexture(bulletTexture);
}
// This method renders the variables score and remaining ammo into the bar at the top of the application.
void SDLPlayer :: showScore(){

    SDL_Rect backgroundPos;
    backgroundPos.h = topBarHeight;
    backgroundPos.w = 640;
    backgroundPos.x = 0;
    backgroundPos.y = 0;

    TTF_Init();
    font = TTF_OpenFont("../Images/OpenSans-Bold.ttf", 24);

    // The integer variables get transformed into a string and a surface gets created with the string.
    string s = "score: " + to_string(score);
    stringstream ss;
    ss << score;
    scoreSurface = TTF_RenderText_Solid(font,s.c_str(), textColor);
    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    string v = "ammo: " + to_string(amountOfAmmo);
    stringstream vv;
    vv << amountOfAmmo;
    bulletSurface = TTF_RenderText_Solid(font,v.c_str(), textColor);
    bulletTexture = SDL_CreateTextureFromSurface(renderer, bulletSurface);

    // The locations of where the information in the topbar should reside is set here.
    SDL_Rect scorePos;
    scorePos.h = scoreSurface -> h;
    scorePos.w = scoreSurface -> w;
    scorePos.x = 310 - scoreSurface -> w/2;
    scorePos.y = 10;

    SDL_Rect bulletPos;
    bulletPos.h = bulletSurface -> h;
    bulletPos.w = bulletSurface -> w;
    bulletPos.x = 10;
    bulletPos.y = 10;

    SDL_FreeSurface(scoreSurface);
    SDL_FreeSurface(bulletSurface);

    SDL_RenderCopy(renderer, topBarTexture,  NULL, &backgroundPos);
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scorePos);
    SDL_RenderCopy(renderer,bulletTexture, NULL, &bulletPos);
    TTF_CloseFont(font);
    // It is important the the textures get destroyed after every gameloop since the values of change so a new Texture
    // from a new Surface has to be created every time.
    SDL_DestroyTexture(scoreTexture);
    SDL_DestroyTexture(bulletTexture);
}
