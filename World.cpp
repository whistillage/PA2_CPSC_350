#include "World.h"

// Constructor
World::World(int gameInfo[]){
    _gameInfo = gameInfo;

    // dynamically assign an array of pointers of class 'Level'
    _levels = new Level*[_gameInfo[0]];
}

// Destructor
World::~World(){
    delete[] _levels;
}

// call createLevel() and assign pointers of Levels, in _levels
void World::createLevels(){
    // seed random for construction of class 'Level'
    // !!! DO NOT MODIFY !!!
    srand(time(0));

    int level;
    // create levels WITH warp portal, unless it is a last stage
    for (level = 0; level < _gameInfo[0] - 1; level++){
        _levels[level] = createLevel(false);
    }

    // create a level WITHOUT warp portal, if it is a last stage
    _levels[level] = createLevel(true);
}

// create a class 'Level' and return its pointer
// if it is the last stage, then create WITHOUT a warp, vice versa
Level* World::createLevel(bool isLastStage){
    Level* newLevel = new Level(_gameInfo, isLastStage);
    return newLevel;
}

Level* World::getLevel(int levelNum){
    return _levels[levelNum];
}

// return # of levels
int World::getLastLevelNum(){
    return _gameInfo[0] - 1;
}

// print all levels on cmd
void World::printLevels(){
    cout << "Build a world! Each Level below: " << endl;
    for (int level = 0; level < _gameInfo[0]; level++){
        cout << "Level " << level + 1 << ": "<< endl;
        for (int row = 0; row < _gameInfo[1]; row++){
            cout << "Row " << row << ": ";
            for (int col = 0; col < _gameInfo[1]; col++){
                cout << _levels[level]->getGrid()[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "============================" << endl; 
}            

// print the level of LevelNum on cmd
void World::printLevel(int LevelNum){
    cout << "Current Level is " << LevelNum + 1 << "." << endl;
    for (int row = 0; row < _gameInfo[1]; row++){
        cout << "Row " << row << ": ";
        for (int col = 0; col < _gameInfo[1]; col++){
            cout << _levels[LevelNum]->getGrid()[row][col] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------" << endl;
}