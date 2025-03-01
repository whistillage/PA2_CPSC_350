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
char Level::getRandomItem(int prob_c, int prob_x, int prob_g, int prob_k, int prob_m){
    // array of random items(char)
    char return_arr[] = {'c', 'x', 'g', 'k', 'm'};

    // array of given probabilities of items
    int prob_arr[] = {prob_c, prob_x, prob_g, prob_k, prob_m};

    // using accumulation of the probabilities
    // create a random number: 0~99
    int random_num = rand() % 100;
    for (int item_idx = 0; item_idx < 5; item_idx++){
        if (random_num < prob_arr[item_idx]){
            return return_arr[item_idx];
        }
        random_num -= prob_arr[item_idx];
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
    int boss_RowIndex = rand() % (_dimension);
    int boss_ColIndex = rand() % (_dimension);
    _grid[boss_RowIndex][boss_ColIndex] = 'b';

    // create the warp pipe in a random position
    if (!isLastStage) {
        int warpPipe_RowIndex, warpPipe_ColIndex;
        
        // make sure that warp pipe not replace the boss
        do {
            warpPipe_RowIndex = rand() % (_dimension);
            warpPipe_ColIndex = rand() % (_dimension);
        } while ((warpPipe_RowIndex == boss_RowIndex) && (warpPipe_ColIndex == boss_ColIndex));

        _grid[warpPipe_RowIndex][warpPipe_ColIndex] = 'w';
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
