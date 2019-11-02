//
// Created by Cedric Plouvier on 2019-04-26.
//

#ifndef CARGAME_PLAYER_H
#define CARGAME_PLAYER_H

#include <string>
#include <iostream>
#include <SDL.h>

using namespace std;

class Player {
public:
    Player();

    bool quit;
    bool paused;

    virtual ~Player();
    void upScore(int s);
    virtual void showScore();
    void setQuit();
    bool getQuit();
    void togglePause();

    int score;
    int amountOfAmmo;
    // topbarHeight is the Height of the bar where all player variables get represented during the game.
    static const int topBarHeight=50;

};


#endif //CARGAME_PLAYER_H
