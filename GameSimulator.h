#ifndef GAMESIMULATOR_H // Header guard to prevent multiple inclusions
#define GAMESIMULATOR_H

#include "World.h"
#include "Mario.h"
using namespace std;

class GameSimulator {
    private:
        // current Level Number
        int _levelNum;

    public:
        // Constructor
        GameSimulator();

        // Destructor
        ~GameSimulator();

        // if win, return 1
        // if gameover, return 0
        int initGame(int* gameInfo);

        void marioInteraction(Mario* mario, World* world);
};

#endif // End of header guard