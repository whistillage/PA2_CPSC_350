#include "Level.h"

/*
x - nothing
m - a mushroom
c - a coin
g - a Goomba
k - a Koopa Troopa
b - the level boss
w - a warp pipe
H - stands for hero. Mario’s current position.
*/

// Constructor
Level::Level(int* gameInfo, bool isLastStage){
    _dimension = gameInfo[1];
    
    // dynamically allocate _grid (nXn array)
    _grid = new char*[_dimension];
    for (int i = 0; i < _dimension; i++){
        _grid[i] = new char[_dimension];
        for (int j = 0; j < _dimension; j++){
            _grid[i][j] = 'A';
        }
    }

    // fill in _grid with x, m, c, g, k

    // create the level boss in a random position
    int boss_RowIndex = rand() % (_dimension);
    int boss_ColIndex = rand() % (_dimension);
    _grid[boss_RowIndex][boss_ColIndex] = 'b';

    // create the warp pipe in a random position
    if (!isLastStage) {
        int warpPipe_RowIndex, warpPipe_ColIndex;
        
        // warp pipe must not replace the boss
        do {
            warpPipe_RowIndex = rand() % (_dimension);
            warpPipe_ColIndex = rand() % (_dimension);
        } while (warpPipe_RowIndex == boss_RowIndex && warpPipe_ColIndex == boss_ColIndex);

        _grid[warpPipe_RowIndex][warpPipe_ColIndex] = 'w';
    }

}

// Destructor
Level::~Level(){
    for (int i = 0; i < _dimension; i++){
        delete[] _grid[i];
    }

    delete[] _grid;
}

char** Level::getGrid(){
    return _grid;
}

