//
// Created by Cedric Plouvier on 2019-06-15.
//

#include "EventHandler.h"

EventHandler::EventHandler() {}

EventHandler::~EventHandler() {}

void EventHandler :: pollEvent(Car* C, Bullet* b, Player* p){
}

void EventHandler ::pollEventPause(Player *p) {
}
// Event to change the players car position 5 pixels up
void EventHandler :: eventUp(Car* C){
    C -> Entity :: updatePosition(0,-5);
}
// Event to change the players car position 5 pixels down
void EventHandler :: eventDown(Car* C){
    C -> Entity :: updatePosition(0,4);
}
// Event to change the players car position 5 pixels left
void EventHandler :: eventLeft(Car*C){
    C -> Entity :: updatePosition(-5,0);
}
// Event to change the players car position 5 pixels right
void EventHandler :: eventRight(Car* C){
    C -> Entity :: updatePosition(5,0);
}
// Event to change the players car position 5 pixels up and left
void EventHandler ::eventLeftUp(Car* C) {
    C -> Entity :: updatePosition(-5,-5);
}
// Event to change the players car position 5 pixels up and right
void EventHandler :: eventRightUp(Car* C){
    C -> Entity :: updatePosition(5,-5);
}
// Function that gets called when spaced is pressed (when not paused) to shoot a bullet
// If the bullet is out of the screen and we still have bullets left we set the position of the bullet to where
// the player car. It always keep visualising upwards untill this function gets called again.
void EventHandler :: eventSpace(Car* C, Bullet* b, Player* p){
    pair <int,int> carPos = C -> Entity :: getPos();
    pair<int,int> bulletPos = b -> Entity :: getPos();

    if (bulletPos.second < 0 && p -> amountOfAmmo > 0) {
        b->Entity::setPosition(carPos.first + C->carWidth / 2 - b->bulletWidth / 2, carPos.second);
        p -> amountOfAmmo-=1;
    }
}
// Method called when the application is quit
void EventHandler :: eventQuit(Player* p){
    p -> setQuit();
}
// Method called when p is pressed to pause or unpause the game
void EventHandler ::eventPause(Player *p) {
    p -> togglePause();
}


