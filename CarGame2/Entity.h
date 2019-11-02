//
// Created by Cedric Plouvier on 2019-04-22.
//

#ifndef CARGAME_ENTITY_H
#define CARGAME_ENTITY_H

#include <utility>
#include <SDL.h>

using namespace std;

class Entity {
public:
    Entity();
    virtual ~Entity();

    virtual bool vis(SDL_Renderer* r,SDL_Texture* texture, int level);
    void updatePosition(int xpos, int ypos);
    void setPosition(int xPosition, int yPosition);
    pair<int,int> getPos();
    pair<int, int> position;
};


#endif //CARGAME_ENTITY_H
