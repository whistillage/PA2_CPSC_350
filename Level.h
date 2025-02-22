#ifndef LEVEL_H // Header guard to prevent multiple inclusions
#define LEVEL_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Level {
    private:
        int _dimension;
        char** _grid;
    public:
        // Default Constructor
        Level(int* gameInfo, bool isLastStage);

        // Destructor
        ~Level();

        char** getGrid();
};

#endif // End of header guard