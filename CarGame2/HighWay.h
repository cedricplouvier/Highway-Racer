//
// Created by Cedric Plouvier on 2019-03-25.
//

#ifndef CARGAME_HIGHWAY_H
#define CARGAME_HIGHWAY_H

#include <SDL.h>
#include <iostream>

class HighWay {
public:
    HighWay();
    virtual ~HighWay();

    virtual bool vis();

    int highWayPosX;
    int highWayPosY;

    // The total lengt of the highway. The highway is 3 times as high as the windows (900 px)
    static int const highway_width = 640;
    static int const highway_height = 2700;
};


#endif //CARGAME_HIGHWAY_H
