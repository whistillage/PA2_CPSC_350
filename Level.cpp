#include "Level.h"

// Default Constructor
Level::Level(int* gameInfo, bool isLastStage){
    _dimension = gameInfo[1];
    _grid = new char*[_dimension];
    for (int i = 0; i < _dimension; i++){
        _grid[i] = new char[_dimension];
        for (int j = 0; j < _dimension; j++){
            _grid[i][j] = 'A';
        }
    }
}
// Destructor
Level::~Level(){
    for (int i = 0; i < _dimension; i++){
        delete[] _grid[i];
    }

    delete[] _grid;
}

