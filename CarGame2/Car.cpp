//
// Created by Cedric Plouvier on 2019-03-18.
//

#include "Car.h"
#include <iostream>

using namespace std;

// Contructor of the player car that immediatly sets its starting position
Car::Car() {
    Entity :: setPosition(270,750);
}

Car::~Car() {}

bool Car :: vis(){
    return 0;
}






