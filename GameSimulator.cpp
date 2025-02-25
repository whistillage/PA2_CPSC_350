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

    // set Mario in a random position in lev 0
    Mario* mario = new Mario(gameInfo[1], gameInfo[2]);

    while (!mario->isGameOver()){
        world->printLevel(_levelNum);
        marioInteraction(mario, world);
        if (mario->isDead()){
            mario->newLife();
        }
        else{
            mario->move(gameInfo[1]);
        }
    }

    delete mario;
    delete world;
}

void GameSimulator::marioInteraction(Mario* mario, World* world){
    int* marioPosition = mario->getPosition();
    cout << "Mario Position: " << marioPosition[0] << ", " << marioPosition[1] << endl;

    // grid of current Level
    char** grid = world->getLevel(_levelNum)->getGrid();

    // according to the item in the position,
    switch (grid[marioPosition[0]][marioPosition[1]]){
        case 'x':
            cout << "Nothing!" << endl;
            break;
        case 'm':
            cout << "Mushroom!" << endl;
            mario->increasePowerLev();
            grid[marioPosition[0]][marioPosition[1]] = 'x';
            break;
        case 'c':
            cout << "Coin!" << endl;
            mario->increaseCoins();
            grid[marioPosition[0]][marioPosition[1]] = 'x';
            break;
        case 'g': {
            cout << "Goomba!" << endl;

            // random integer: 0 ~ 9
            int randNum = rand() % 10;

            // if mario wins in prob of 80%,
            if (randNum < 8){
                grid[marioPosition[0]][marioPosition[1]] = 'x';
            }
            // if mario loses in prob of 20%,
            else{
                mario->getDamage();
            }

            break;
        }
        case 'k':
            cout << "Koopa!" << endl;
            break;
        case 'b':
            cout << "Boss!" << endl;
            break;
        case 'w':
            cout << "Warp Pipe!" << endl;
            break;
    }
}