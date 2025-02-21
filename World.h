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

        /*Values below sum to 100*/
        int _Percentage_of_Coins;       // percentage of positions in each level with coins (a poistive integer)
        int _Percentage_of_Nothing;     // percentage of positions in each level with nothing (a poistive integer)
        int _Percentage_of_Goombas;     // percentage of positions in each level with Goombas (a poistive integer)
        int _Percentage_of_Koopas;      // percentage of positions in each level with Koopas (a poistive integer)
        int _Percentage_of_Mushrooms;   // percentage of positions in each level with mushrooms (a poistive integer)

        /*Array of pointers of class 'Level'*/
        Level** _levels;
    public:
        // Parameterized Constructor
        World(int gameInfo[]);

        // Destructor
        ~World();

        void printGameInfo();

        // createLevel을 통해 level들을 할당하고 _levels array에 저장
        void createLevels();
        Level* createLevel();
};

#endif // End of header guard