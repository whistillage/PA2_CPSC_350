// AUTHOR INFO
// Full Name: Taehyun Kim (with Danica)
// Student ID: 2484228
// Chapman Email: taehykim@chapman.edu
// Course Number & Section: CPSC-350-01
// Assignment Number: PA 2: Not so Super Mario Bros.
#ifndef LEVEL_H // Header guard to prevent multiple inclusions
#define LEVEL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Level {
    private:
        // dimension of the grid
        int _dimension;

        // n X n array of char
        char** _grid;

        // According to the given probability of each item, return a random item(char)
        char getRandomItem(int probC, int probX, int probG, int probK, int probM);

    public:
        // Constructor
        Level(int* gameInfo, bool isLastStage);

        // Destructor
        ~Level();

        // return _grid (nXn array of char)
        char** getGrid();
};

#endif // End of header guard