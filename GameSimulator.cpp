#include "GameSimulator.h"

// Constructor
GameSimulator::GameSimulator(){

}

// Destructor
GameSimulator::~GameSimulator(){

}

void GameSimulator::initGame(int* gameInfo){
    World myWorld(gameInfo);
    myWorld.createLevels();
    myWorld.printLevels();
}
