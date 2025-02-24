#ifndef GAMESIMULATOR_H // Header guard to prevent multiple inclusions
#define GAMESIMULATOR_H

#include "World.h"
#include "Mario.h"
using namespace std;

class GameSimulator {
    private:

    public:
        // Constructor
        GameSimulator();

        // Destructor
        ~GameSimulator();

        void initGame(int* gameInfo);
};

#endif // End of header guard