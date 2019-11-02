//
// Created by Cedric Plouvier on 2019-04-22.
//

#include <iostream>
#include "Entity.h"

using namespace std;

Entity::Entity() {}
Entity::~Entity() {}

bool Entity :: vis(SDL_Renderer* r, SDL_Texture* texture, int level){
    return 0;
}
// Changes the entities position by a given x and y coordinate in pixels
void Entity :: updatePosition(int xpos, int ypos){
    position.first += xpos;
    position.second += ypos;
}
// Returns the position of the entity that calls this function.
pair<int,int> Entity :: getPos(){
    return position;
}
// Sets the entity at a certain position
void Entity :: setPosition(int xPosition, int yPosition){
    position.first = xPosition;
    position.second = yPosition;
}


