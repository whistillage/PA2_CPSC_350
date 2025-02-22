#ifndef WORLD_H // Header guard to prevent multiple inclusions
#define WORLD_H

#include <iostream>
#include "Level.h"
using namespace std;

class World {
    private:
        // pointer of, an array of game information
        int* _gameInfo;

        // array of, pointers of class 'Level'
        Level** _levels;

    public:
        // Constructor
        World(int gameInfo[]);

        // Destructor
        ~World();

        // call createLevel() and assign pointers of Levels, in _levels
        void createLevels();

        // create a class 'Level' and return its pointer
        // if it is the last stage, then create WITHOUT a warp, vice versa
        Level* createLevel(bool isLastStage);

        // print all levels on cmd
        void printLevels();
};

#endif // End of header guard