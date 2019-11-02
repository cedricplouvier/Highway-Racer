//
// Created by Cedric Plouvier on 2019-04-25.
//

#ifndef CARGAME_MENU_H
#define CARGAME_MENU_H
#include <SDL.h>
#include <iostream>

using namespace std;


class Menu {
public:
    Menu();
    virtual ~Menu();
    virtual bool startMenu();
    virtual void gameOver();
};


#endif //CARGAME_MENU_H
