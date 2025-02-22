#ifndef WORLD_H // Header guard to prevent multiple inclusions
#define WORLD_H

#include <iostream>
#include <fstream>
#include <string>
#include "Level.h"
using namespace std;

class World {
    private:
        // pointer for array of game information
        int* _gameInfo;

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