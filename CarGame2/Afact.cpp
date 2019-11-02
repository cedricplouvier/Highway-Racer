//
// Created by Cedric Plouvier on 2019-03-04.
//

#include <iostream>
#include "Afact.h"

using namespace std;

Afact::Afact(){}

Afact::~Afact() {
}

Car* Afact::createCar() {
    cout << "Afact car is created" <<endl;
}

HighWay* Afact::createHighWay() {
    cout << "HighWay Afact with renderer" << endl;
}

EnemyCar* Afact::createEnemyCar() {
    cout << "Enemy car created in Afact" << endl;
}

Bullet* Afact::createBullet() {
    cout << "Bullet created in Afact" << endl;
}

Menu* Afact :: createMenu(){
    cout << "menu created" << endl;
}

Player* Afact :: createPlayer(){
    cout << "player created" << endl;
}

EventHandler* Afact :: createEventHandler(){
}

PowerUpAmmo* Afact :: createPowerUpAmmo(){
    cout << "Afact PowerupsAmmo created" << endl;
}

PowerUpCoin* Afact :: createPowerUpCoin() {
    cout << "Afact PowerupsCoin created" << endl;
}










