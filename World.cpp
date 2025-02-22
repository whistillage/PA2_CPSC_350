#include "World.h"

// Parameterized Constructor
World::World(int gameInfo[]){
    _gameInfo = gameInfo;
}

// Destructor
World::~World(){
}

void World::createLevels(){
    int NumLevels = _gameInfo[0];

    // dynamically assign an array of pointers of class 'Level'
    _levels = new Level*[NumLevels];

    // create levels WITH warp unless it is a last stage
    for (int i = 0; i < NumLevels - 1; i++){
        _levels[i] = createLevel(false);
    }

    // create a level WITHOUT warp if it is a last stage
    _levels[-1] = createLevel(true);
}

Level* World::createLevel(bool isLastStage){
    Level* newLevel = new Level(_gameInfo, isLastStage);
    return newLevel;
}