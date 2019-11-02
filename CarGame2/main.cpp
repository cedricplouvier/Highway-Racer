#include <iostream>
#include "Game.h"
#include "SDLfact.h"
#include "SDLEventHandler.h"

using namespace std;


// We create an instance of our SDLfactory which we store in its Abstract factory parent class.
// A Game instance is created and given abstract factory as parameter.
// The game starts by calling the start() method.
int main() {
    Afact* F = new SDLfact();
    EventHandler* E = new SDLEventHandler();
    Game* G = new Game(F);
    G -> start();
}


