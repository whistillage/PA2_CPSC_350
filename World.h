#ifndef WORLD_H // Header guard to prevent multiple inclusions
#define WORLD_H

#include <iostream>
#include <fstream>
#include <string>
#include "Level.h"
using namespace std;

class World {
    private:
        int _L;                         // # of levels (a positive integer)
        int _N;                         // dimension of grid (a positive integer)
        int _V;                         // # of initial lives (a positive integer)

        // Values below sum to 100
        int _Percentage_of_Coins;       // percentage of positions in each level with coins (a poistive integer)
        int _Percentage_of_Nothing;     // percentage of positions in each level with nothing (a poistive integer)
        int _Percentage_of_Goombas;     // percentage of positions in each level with Goombas (a poistive integer)
        int _Percentage_of_Koopas;      // percentage of positions in each level with Koopas (a poistive integer)
        int _Percentage_of_Mushrooms;   // percentage of positions in each level with mushrooms (a poistive integer)

        // Array of pointers of class 'Level'
        Level** _levels;
    public:
        // Parameterized Constructor
        World(int gameInfo[]);

        // Destructor
        ~World();

        // call createLevel and assign pointers of levels in _levels
        void createLevels();

        // create a class 'Level' and return its address
        // if it is a last stage, then create WITHOUT a warp, vice versa
        Level* createLevel(bool isLastStage);
};

#endif // End of header guard