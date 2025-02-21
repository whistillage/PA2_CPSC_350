#include "World.h"

// Parameterized Constructor
World::World(int gameInfo[]){
    _L = gameInfo[0];
    _N = gameInfo[1];
    _V = gameInfo[2];
    _Percentage_of_Coins = gameInfo[3];
    _Percentage_of_Nothing = gameInfo[4];
    _Percentage_of_Goombas = gameInfo[5];
    _Percentage_of_Koopas = gameInfo[6];
    _Percentage_of_Mushrooms = gameInfo[7];}

// Destructor
World::~World(){
}

void World::createLevels(){
    _levels = new Level*[_L];

    // create levels WITH warp unless it is a last stage
    for (int i = 0; i < _L - 1; i++){
        _levels[i] = createLevel(false);
    }

    // create a level WITHOUT warp if it is a last stage
    _levels[-1] = createLevel(true);
}

Level* World::createLevel(bool isLastStage){
    Level newLevel(isLastStage);
    return &newLevel;
}