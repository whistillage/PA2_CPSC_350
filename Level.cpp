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
            // fill in _grid with x, m, c, g, k
            _grid[i][j] = getRandomItem(gameInfo[3], gameInfo[4], gameInfo[5], gameInfo[6], gameInfo[7]);
        }
    }

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

// return _grid (nXn array of char)
char** Level::getGrid(){
    return _grid;
}

char Level::getRandomItem(int prob_c, int prob_x, int prob_g, int prob_k, int prob_m){
    char return_arr[] = {'c', 'x', 'g', 'k', 'm'};
    int prob_arr[] = {prob_c, prob_x, prob_g, prob_k, prob_m};

    // create a random number: 0~99
    int random_num = rand() % 100;
    for (int i = 0; i < 5; i++){
        if (random_num < prob_arr[i]){
            return return_arr[i];
        }
        random_num -= prob_arr[i];
    }

    /* Below is printed if the sum of input probabilities is less than 100 */
    cout << "The Sum of Input Probabilities is less than 100. Inappropriate Input Error." << endl;
}