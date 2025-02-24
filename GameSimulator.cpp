#include "GameSimulator.h"

// Constructor
GameSimulator::GameSimulator(){

}

// Destructor
GameSimulator::~GameSimulator(){

}

void GameSimulator::initGame(int* gameInfo){
    World* world = new World(gameInfo);
    world->createLevels();
    world->printLevels();

    Mario* mario = new Mario(gameInfo[2]);

    delete mario;
    delete world;
}
