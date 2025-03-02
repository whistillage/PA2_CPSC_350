#include "GameSimulator.h"

// Constructor
GameSimulator::GameSimulator(){
    _curLevelNum = 0;
    _moveCount = 0;
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
    
    fileProcessor->writeOutputFile("[GAME RESULT]");
    // if Mario wins the game,
    if (gameResult == 1){
        fileProcessor->writeOutputFile("Mario Win!!! ");
    }
    // if game over,
    else if (gameResult == 0){
        fileProcessor->writeOutputFile("Mario Lose...");
    }
    // error
    else{
        fileProcessor->writeOutputFile("Error");
    }
    fileProcessor->writeOutputFile("Total moves: " + to_string(_moveCount));

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
            fileProcessor->writeOutputFile("Mario will go to next level.");
            mario->setRandPosition(_gameInfo[1], fileProcessor, _curLevelNum);
            continue;
        }
        // move into a new position
        mario->move(_gameInfo[1], fileProcessor);
    }

    if (mario->isWon()){
        returnNum = 1;
    }
    if (mario->isGameOver()){
        returnNum = 0;
    }

    _moveCount = mario->getMoveCount();

    delete mario;
    delete world;

    return returnNum;
}

void GameSimulator::marioInteraction(Mario* mario, World* world, FileProcessor* fileProcessor){
    int* marioPosition = mario->getPosition();
    fileProcessor->writeOutputFile("Level: "+ to_string(_curLevelNum) \
    + ". Mario is at position: (" + to_string(marioPosition[0]) + "," + to_string(marioPosition[1]) \
    + "). Mario is at power level " + to_string(mario->getPowerLev()) \
    + ". ", false);

    // grid of current Level
    char** grid = world->getLevel(_curLevelNum)->getGrid();

    // according to the item in the position,
    switch (grid[marioPosition[0]][marioPosition[1]]){
        case 'x': {
            fileProcessor->writeOutputFile("Mario visited an empty space. ", false);
            break;
        }
        case 'm' : {
            fileProcessor->writeOutputFile("Mario ate a mushroom. ", false);
            mario->increasePowerLev();
            grid[marioPosition[0]][marioPosition[1]] = 'x';
            break;
        }
        case 'c': {
            fileProcessor->writeOutputFile("Mario collected a coin. ", false);
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
                fileProcessor->writeOutputFile("Mario encountered a goomba and won. ", false);
                grid[marioPosition[0]][marioPosition[1]] = 'x';
            }
            // if mario loses in prob of 20%,
            else{
                fileProcessor->writeOutputFile("Mario encountered a goomba and lost. ", false);
                mario->damaged(1);
            }
            break;
        }
        case 'k' : {
            // random integer: 0 ~ 99
            int randNum = rand() % 100;

            // if mario defeats in prob of 65%,
            if (randNum < 65){
                mario->defeatEnemy();
                fileProcessor->writeOutputFile("Mario encountered a koopa and won. ", false);
                grid[marioPosition[0]][marioPosition[1]] = 'x';
            }
            // if mario loses in prob of 35%,
            else{
                fileProcessor->writeOutputFile("Mario encountered a koopa and lost. ", false);
                mario->damaged(1);
            }
            break;
        }
        case 'b': {
            // random integer: 0 ~ 99
            int randNum = rand() % 100;

            // if mario defeats in prob of 50%,
            if (randNum < 50){
                fileProcessor->writeOutputFile("Mario encountered the boss and won. ", false);
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
                fileProcessor->writeOutputFile("Mario encountered the boss and lost. ", false);
                mario->damaged(2);
            }
            break;
        }
        case 'w':
        fileProcessor->writeOutputFile("Mario visited a warp pipe. ", false);
            mario->warp();
            break;
    }

    /* EX) Mario has 2 lives left.*/
    fileProcessor->writeOutputFile("Mario has " + to_string(mario->getLives()) + " lives left. ", false);
    /* EX) Mario has 1 coins.*/
    fileProcessor->writeOutputFile("Mario has " + to_string(mario->getCoins()) + " coins. ", false);
}