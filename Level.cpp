// AUTHOR INFO
// Full Name: Taehyun Kim (with Danica)
// Student ID: 2484228
// Chapman Email: taehykim@chapman.edu
// Course Number & Section: CPSC-350-01
// Assignment Number: PA 2: Not so Super Mario Bros.
#include "Level.h"

/* symbol char of items:
    x - nothing
    m - a mushroom
    c - a coin
    g - a Goomba
    k - a Koopa Troopa
    b - the level boss
    w - a warp pipe
    H - stands for hero. Mario’s current position.
*/

// According to the given probability of each item, return a random item(char)
char Level::getRandomItem(int probC, int probX, int probG, int probK, int probM){
    // array of random items(char)
    char returnArr[] = {'c', 'x', 'g', 'k', 'm'};

    // array of given probabilities of items
    int probArr[] = {probC, probX, probG, probK, probM};

    // using accumulation of the probabilities
    // create a random number: 0~99
    int randomNum = rand() % 100;
    for (int itemIdx = 0; itemIdx < 5; itemIdx++){
        if (randomNum < probArr[itemIdx]){
            return returnArr[itemIdx];
        }
        randomNum -= probArr[itemIdx];
    }
}

// Constructor
Level::Level(int* gameInfo, bool isLastStage){
    _dimension = gameInfo[1];
    
    // dynamically allocate _grid
    _grid = new char*[_dimension];
    for (int row = 0; row < _dimension; row++){
        _grid[row] = new char[_dimension];
        for (int col = 0; col < _dimension; col++){
            // fill in _grid with x, m, c, g, k
            _grid[row][col] = getRandomItem(gameInfo[3], gameInfo[4], gameInfo[5], gameInfo[6], gameInfo[7]);
        }
    }

    // create the level boss in a random position
    int bossRowIndex = rand() % (_dimension);
    int bossColIndex = rand() % (_dimension);
    _grid[bossRowIndex][bossColIndex] = 'b';

    // create the warp pipe in a random position
    if (!isLastStage) {
        int warpPipeRowIndex, warpPipeColIndex;
        
        // make sure that warp pipe not replace the boss
        do {
            warpPipeRowIndex = rand() % (_dimension);
            warpPipeColIndex = rand() % (_dimension);
        } while ((warpPipeRowIndex == bossRowIndex) && (warpPipeColIndex == bossColIndex));

        _grid[warpPipeRowIndex][warpPipeColIndex] = 'w';
    }

}

// Destructor
Level::~Level(){
    for (int row = 0; row < _dimension; row++){
        delete[] _grid[row];
    }

    delete[] _grid;
}

// return _grid (nXn array of char)
char** Level::getGrid(){
    return _grid;
}
