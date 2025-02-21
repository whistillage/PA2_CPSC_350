/*
Each level in our game is represented by a NxN grid (think 2D array), with N provided at runtime. Mario may navigate the grid by moving up, down, left, and right only. The grid wraps horizontally and vertically (a torus). For example, if Mario is in the rightmost column and moves right, he will wrap to the same row in the leftmost column.
 
Every position in the grid can be populated with one of the following:
A coin
A mushroom
A Goomba or a Koopa Troopa
The boss of the level (there must be exactly 1 per level)
Nothing
 
Additionally, every level from 1 to L-1 contains a SINGLE warp pipe somewhere on the grid. Note that the final level does not contain a warp pipe.
*/

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
        Level();

        // Destructor
        ~Level();

        Level(int P_coins, int P_nothing, int P_);
};

#endif // End of header guard