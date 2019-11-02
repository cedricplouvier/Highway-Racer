//
// Created by Cedric Plouvier on 2019-03-04.
//

#ifndef CARGAME_AFACT_H
#define CARGAME_AFACT_H

#include "Car.h"
#include "HighWay.h"
#include "EnemyCar.h"
#include "Menu.h"
#include "Player.h"
#include "Bullet.h"
#include "EventHandler.h"
#include "PowerUpAmmo.h"
#include "PowerUpCoin.h"

class Afact {
    public:
        Afact();
        virtual ~Afact();
        virtual Car* createCar();
        virtual HighWay* createHighWay();
        virtual EnemyCar* createEnemyCar();
        virtual Menu* createMenu();
        virtual Player* createPlayer();
        virtual Bullet* createBullet();
        virtual EventHandler* createEventHandler();
        virtual PowerUpAmmo* createPowerUpAmmo();
        virtual PowerUpCoin* createPowerUpCoin();

    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 900;
};


#endif //CARGAME_AFACT_H
