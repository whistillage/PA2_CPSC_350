#include "World.h"

// Parameterized Constructor
World::World(int gameInfo[]){
    _gameInfo = gameInfo;

    // dynamically assign an array of pointers of class 'Level'
    _levels = new Level*[_gameInfo[0]];
}

// Destructor
World::~World(){
    delete[] _levels;
}

void World::createLevels(){
    int level;
    // create levels WITH warp unless it is a last stage
    for (level = 0; level < _gameInfo[0] - 1; level++){
        _levels[level] = createLevel(false);
    }

    // create a level WITHOUT warp if it is a last stage
    _levels[level] = createLevel(true);
}

Level* World::createLevel(bool isLastStage){
    Level* newLevel = new Level(_gameInfo, isLastStage);
    return newLevel;
}

void World::printLevels(){
    for (int level = 0; level < _gameInfo[0]; level++){
        cout << "Level " << level << ": "<< endl;
        for (int row = 0; row < _gameInfo[1]; row++){
            cout << "Row " << row << ": ";
            for (int col = 0; col < _gameInfo[1]; col++){
                cout << _levels[level]->getGrid()[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    
}