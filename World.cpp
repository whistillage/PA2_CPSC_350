#include "World.h"

// Constructor
World::World(int gameInfo[]){
    _gameInfo = gameInfo;

    // dynamically assign an array of pointers of class 'Level'
    _levels = new Level*[_gameInfo[0]];

    // seed random for construction of class 'Level'
    // !!! DO NOT MODIFY !!!
    srand(time(0));
}

// Destructor
World::~World(){
    for (int i = 0; i < _gameInfo[0]; i++){
        delete _levels[i];
    }
    delete[] _levels;
}

// call createLevel() and assign pointers of Levels, in _levels
void World::createLevels(){
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

// print all levels
void World::printLevels(FileProcessor* fileProcessor){
    fileProcessor->writeOutputFile("[INITIAL WORLD]");
    for (int level = 0; level < _gameInfo[0]; level++){
        fileProcessor->writeOutputFile("");
        fileProcessor->writeOutputFile("Level " + to_string(level + 1) + ": ");
        for (int row = 0; row < _gameInfo[1]; row++){
            string line = "";
            for (int col = 0; col < _gameInfo[1]; col++){
                line.push_back(_levels[level]->getGrid()[row][col]);
            }
            fileProcessor->writeOutputFile(line);
        }
    }
    fileProcessor->writeOutputFile("");
    fileProcessor->writeOutputFile("#######################################");
}            

// print the level of LevelNum, with mario in position[2]
void World::printLevelwithMario(int LevelNum, int* position, FileProcessor* fileProcessor){
    for (int row = 0; row < _gameInfo[1]; row++){
        string line = "";
        for (int col = 0; col < _gameInfo[1]; col++){
            line.push_back(_levels[LevelNum]->getGrid()[row][col]);
        }
        // mark 'H' on Mario's current position
        if (row == position[0]){
            line[position[1]] = 'H';
        }
        fileProcessor->writeOutputFile(line);
    }
    fileProcessor->writeOutputFile("================");
}