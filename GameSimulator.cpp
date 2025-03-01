#include "GameSimulator.h"

// Constructor
GameSimulator::GameSimulator(){
    _curLevelNum = 0;
}

// Destructor
GameSimulator::~GameSimulator(){

}

void GameSimulator::initGame(const char* inputFile, const char* outputFile){
    FileProcessor* fileProcessor = new FileProcessor();

    // if failed to read input file, terminate the program.
    if (!fileProcessor->readFiles(inputFile, outputFile, _gameInfo)){
        cout << "Failed to read files. Exit." << endl;
        return;
    }

    int sumOfProb = _gameInfo[3] + _gameInfo[4] + _gameInfo[5] + _gameInfo[6] + _gameInfo[7];
    if (sumOfProb != 100){
        cout << "The Sum of probabilities is not equal to 100. Exit." << endl;
        return;
    }

    int gameResult = playGame(fileProcessor);
    // if Mario wins the game,
    if (gameResult == 1){
        fileProcessor->writeOutputFile("Win!!!");
    }
    // if game over,
    else if (gameResult == 0){
        fileProcessor->writeOutputFile("Lose...");
    }
    // error
    else{
        fileProcessor->writeOutputFile("Error");
    }

    fileProcessor->closeFiles();
}

int GameSimulator::playGame(FileProcessor* fileProcessor){
    // integer variable for return value
    int returnNum = -1;

    World* world = new World(_gameInfo);
    world->createLevels();
    world->printLevels(fileProcessor);

    Mario* mario = new Mario(_gameInfo[2]);
    mario->setRandPosition(_gameInfo[1], fileProcessor, _curLevelNum);

    while (!mario->isGameOver() && !mario->isWon()){
        world->printLevelwithMario(_curLevelNum, mario->getPosition(), fileProcessor);
        marioInteraction(mario, world, fileProcessor);

        // if mario is warping to next level, increase levelNum and move to random position.
        // skip revival or moving.
        if (mario->isWarping()){
            _curLevelNum += 1;
            mario->setRandPosition(_gameInfo[1], fileProcessor, _curLevelNum);
            continue;
        }

        // if mario is dead, get a new life in the same position.
        if (mario->isDead()){
            mario->revive();
        }
        // if mario is not dead, move into a new position.
        else{
            mario->move(_gameInfo[1]);
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

void GameSimulator::marioInteraction(Mario* mario, World* world, FileProcessor* fileProcessor){
    int* marioPosition = mario->getPosition();
    fileProcessor->writeOutputFile("Level: "+ to_string(_curLevelNum) \
    + ". Mario is at position: (" + to_string(marioPosition[0]) + "," + to_string(marioPosition[1]) \
    + "). Mario is at power level " + to_string(mario->getPowerLev()) \
    + ".");

    // grid of current Level
    char** grid = world->getLevel(_curLevelNum)->getGrid();

    // according to the item in the position,
    switch (grid[marioPosition[0]][marioPosition[1]]){
        case 'x': {
            fileProcessor->writeOutputFile("Mario visited an empty space.");
            break;
        }
        case 'm' : {
            fileProcessor->writeOutputFile("Mario ate a mushroom.");
            mario->increasePowerLev();
            grid[marioPosition[0]][marioPosition[1]] = 'x';
            break;
        }
        case 'c': {
            fileProcessor->writeOutputFile("Mario collected a coin.");
            mario->increaseCoins();
            grid[marioPosition[0]][marioPosition[1]] = 'x';
            break;
        }
        case 'g': {
            // random integer: 0 ~ 99
            int randNum = rand() % 100;

            // if mario defeats in prob of 80%,
            if (randNum < 80){
                mario->defeatEnemy();
                fileProcessor->writeOutputFile("Mario encountered a goomba and won.");
                grid[marioPosition[0]][marioPosition[1]] = 'x';
            }
            // if mario loses in prob of 20%,
            else{
                fileProcessor->writeOutputFile("Mario encountered a goomba and lost.");
                mario->getDamage(1);
            }
            break;
        }
        case 'k' : {
            // random integer: 0 ~ 99
            int randNum = rand() % 100;

            // if mario defeats in prob of 65%,
            if (randNum < 65){
                mario->defeatEnemy();
                fileProcessor->writeOutputFile("Mario encountered a koopa and won.");
                grid[marioPosition[0]][marioPosition[1]] = 'x';
            }
            // if mario loses in prob of 35%,
            else{
                fileProcessor->writeOutputFile("Mario encountered a koopa and lost.");
                mario->getDamage(1);
            }
            break;
        }
        case 'b': {
            // random integer: 0 ~ 99
            int randNum = rand() % 100;

            // if mario defeats in prob of 50%,
            if (randNum < 50){
                fileProcessor->writeOutputFile("Mario encountered the boss and won.");
                // if mario is in the last level,
                if (_curLevelNum == _gameInfo[0] - 1){
                    mario->winGame();
                }
                else{
                    mario->warp();
                }
            }
            // if mario loses in prob of 50%,
            else{
                fileProcessor->writeOutputFile("Mario encountered the boss and lost.");
                mario->getDamage(2);
            }
            break;
        }
        case 'w':
        fileProcessor->writeOutputFile("Mario visited a warp pipe.");
            mario->warp();
            break;
    }

    fileProcessor->writeOutputFile("================");
}