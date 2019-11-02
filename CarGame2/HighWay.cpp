//
// Created by Cedric Plouvier on 2019-03-25.
//

#include "HighWay.h"

using namespace std;

// The Highway gets contructed and placed with his left top corner at (0,-1800).
// Since the total length of the highways is 2700 and the window length is 900 there is exactly 900 pixels of
// the highway on the window at the start.
HighWay::HighWay() {
    highWayPosY = -1800;
    highWayPosX = 0;
}
HighWay::~HighWay() {
}

bool HighWay :: vis(){

}