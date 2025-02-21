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

void World::printGameInfo(){
    cout << _L << endl;
    cout << _Percentage_of_Mushrooms << endl;
}

void World::createLevels(){
    _levels = new Level*[_L];
    for (int i = 0; i < _L; i++){
        _levels[i] = createLevel();
    }
}

Level* World::createLevel(){
    // Level을 동적으로 할당해서 포인터를 반환
}