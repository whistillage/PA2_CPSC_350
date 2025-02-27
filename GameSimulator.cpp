#include "GameSimulator.h"

// Constructor
GameSimulator::GameSimulator(){
    _levelNum = 0;
}

// Destructor
GameSimulator::~GameSimulator(){

}

int GameSimulator::initGame(int* gameInfo){
    // integer variable for return value
    int returnNum = -1;

    World* world = new World(gameInfo);
    world->createLevels();
    world->printLevels();

    // set Mario in a random position in lev 0
    Mario* mario = new Mario(gameInfo[1], gameInfo[2]);

    while (!mario->isGameOver() || !mario->isWon()){
        world->printLevel(_levelNum);
        marioInteraction(mario, world);

        // if mario is warping to next level, increase levelNum and move to random position.
        // skip revival or moving.
        if (mario->isWarping()){
            _levelNum += 1;
            mario->setRandPosition(gameInfo[1]);
            continue;
        }

        // if mario is dead, get a new life in the same position.
        if (mario->isDead()){
            mario->revive();
        }
        // if mario is not dead, move into a new position.
        else{
            mario->move(gameInfo[1]);
        }
    }

    if (mario->isWon()){
        returnNum = 1;
    }
    if (mario->isGameOver()){
        returnNum = 0;
    }

    delete mario;
    delete world;

    return returnNum;
}

void GameSimulator::marioInteraction(Mario* mario, World* world){
    int* marioPosition = mario->getPosition();
    cout << "Mario Position: " << marioPosition[0] << ", " << marioPosition[1] << endl;

    // grid of current Level
    char** grid = world->getLevel(_levelNum)->getGrid();

    // according to the item in the position,
    switch (grid[marioPosition[0]][marioPosition[1]]){
        case 'x': {
            cout << "Nothing!" << endl;
            break;
        }
        case 'm' : {
            cout << "Mushroom!" << endl;
            mario->increasePowerLev();
            grid[marioPosition[0]][marioPosition[1]] = 'x';
            break;
        }
        case 'c': {
            cout << "Coin!" << endl;
            mario->increaseCoins();
            grid[marioPosition[0]][marioPosition[1]] = 'x';
            break;
        }
        case 'g': {
            cout << "Goomba!" << endl;

            // random integer: 0 ~ 99
            int randNum = rand() % 100;

            // if mario defeats in prob of 80%,
            if (randNum < 80){
                mario->defeatEnemy();
                grid[marioPosition[0]][marioPosition[1]] = 'x';
            }
            // if mario loses in prob of 20%,
            else{
                mario->getDamage(1);
            }
            break;
        }
        case 'k' : {
            cout << "Koopa!" << endl;

            // random integer: 0 ~ 99
            int randNum = rand() % 100;

            // if mario defeats in prob of 65%,
            if (randNum < 65){
                mario->defeatEnemy();
                grid[marioPosition[0]][marioPosition[1]] = 'x';
            }
            // if mario loses in prob of 35%,
            else{
                mario->getDamage(1);
            }
            break;
        }
        case 'b': {
            cout << "Boss!" << endl;

            // random integer: 0 ~ 99
            int randNum = rand() % 100;

            // if mario defeats in prob of 50%,
            if (randNum < 50){
                // if mario is in the last level,
                if (_levelNum == world->getLastLevelNum()){
                    mario->winGame();
                }
                else{
                    mario->warp();
                }
            }
            // if mario loses in prob of 50%,
            else{
                mario->getDamage(2);
            }
            break;
        }
        case 'w':
            cout << "Warp Pipe!" << endl;
            mario->warp();
            break;
    }
}