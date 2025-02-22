#ifndef LEVEL_H // Header guard to prevent multiple inclusions
#define LEVEL_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Level {
    private:
        // members
    public:
        // Default Constructor
        Level(int* gameInfo, bool isLastStage);

        // Destructor
        ~Level();

        Level(int P_coins, int P_nothing, int P_);
};

#endif // End of header guard