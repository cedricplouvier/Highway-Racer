//
// Created by Cedric Plouvier on 2019-03-04.
//

#ifndef CARGAME_SDLFACT_H
#define CARGAME_SDLFACT_H

#include <stdio.h>
#include <SDL.h>
#include <string>

#include "Afact.h"
#include "SDLcar.h"
#include "SDLHighWay.h"
#include "SDLEnemyCar.h"
#include "SDLMenu.h"
#include "SDLPlayer.h"
#include "SDLBullet.h"
#include "SDLEventHandler.h"
#include "SDLPowerUpAmmo.h"
#include "SDLPowerUpCoin.h"

class SDLfact : public Afact {
    public:
        SDLfact();
        virtual ~SDLfact();
        SDLcar* createCar();
        SDLHighWay* createHighWay();
        SDLEnemyCar* createEnemyCar();
        SDLMenu* createMenu();
        SDLPlayer* createPlayer();
        Bullet* createBullet();
        EventHandler* createEventHandler();
        PowerUpAmmo* createPowerUpAmmo();
        PowerUpCoin* createPowerUpCoin();
private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};


#endif //CARGAME_SDLFACT_H
