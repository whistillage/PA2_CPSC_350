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
        
        // According to the given probability of each item, return a random item(char)
        char getRandomItem(int prob_c, int prob_x, int prob_g, int prob_k, int prob_m);
    public:
        // Constructor
        Level(int* gameInfo, bool isLastStage);

        // Destructor
        ~Level();

        char** getGrid();
};

#endif // End of header guard