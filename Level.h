#ifndef LEVEL_H // Header guard to prevent multiple inclusions
#define LEVEL_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <random>
using namespace std;

class Level {
    private:
        int _dimension;
        char** _grid;
    public:
        // Constructor
        Level(int* gameInfo, bool isLastStage);

        // Destructor
        ~Level();

        char** getGrid();
};

#endif // End of header guard