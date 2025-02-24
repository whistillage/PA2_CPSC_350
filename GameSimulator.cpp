#include "GameSimulator.h"

// Constructor
GameSimulator::GameSimulator(){
    _levelNum = 0;
}

// Destructor
GameSimulator::~GameSimulator(){

}

void GameSimulator::initGame(int* gameInfo){
    World* world = new World(gameInfo);
    world->createLevels();
    world->printLevels();

    Mario* mario = new Mario(gameInfo[2]);

    // set Mario in a random position in lev 0
    int randXpos = rand() % (gameInfo[1]);
    int randYpos = rand() % (gameInfo[1]);
    mario->setPosition(randXpos, randYpos);

    marioInteraction(mario, world);
    world->printLevel(_levelNum);

    delete mario;
    delete world;
}

void GameSimulator::marioInteraction(Mario* mario, World* world){
    int* marioPosition = mario->getPosition();
    cout << "Mario Position: " << marioPosition[0] << ", " << marioPosition[1] << endl;

    // grid of current Level
    char** grid = world->getLevel(_levelNum)->getGrid();
    switch (grid[marioPosition[0]][marioPosition[1]]){
        case 'x':
            cout << "Mario is on x!" << endl;
            break;
        case 'm':
            cout << "Mario is on m!" << endl;
            break;
        case 'c':
            cout << "Mario is on c!" << endl;
            mario->increaseCoins();
            grid[marioPosition[0]][marioPosition[1]] = 'x';
            break;
        case 'g':
            cout << "Mario is on g!" << endl;
            break;
        case 'k':
            cout << "Mario is on k!" << endl;
            break;
        case 'b':
            cout << "Mario is on b!" << endl;
            break;
        case 'w':
            cout << "Mario is on w!" << endl;
            break;
    }
}