#include "Mario.h"

// Constructor
Mario::Mario(int lives){
    _lives = lives;
    _coins = 0;
    _powerLev = 0;
    _defeatStreak = 0;
    _warping = false;
    _win = false;
    _gameOver = false;
    _dead = false;
}

// Destructor
Mario::~Mario(){
}

// set Mario in a random position
void Mario::setRandPosition(int dimension, FileProcessor* fileProcessor, int curLevelNum){
    _position[0] = rand() % (dimension);
    _position[1] = rand() % (dimension);

    fileProcessor->writeOutputFile("Mario is starting Level " + to_string(curLevelNum + 1) \
    + " in position: (" + to_string(_position[0]) + ", " + to_string(_position[1]) + ")");
    fileProcessor->writeOutputFile("================");
    // finished warping.
    _warping = false;
}

int* Mario::getPosition(){
    return _position;
}

// get _powerLev
int Mario::getPowerLev(){
    return _powerLev;
}

// get _lives
int Mario::getLives(){
    return _lives;
}

// get _coins
int Mario::getCoins(){
    return _coins;
}

// increase _coins by 1
void Mario::increaseCoins(){
    _coins += 1;
}

void Mario::increasePowerLev(){
    _powerLev += 1;
    
    // power level does not extend 2
    if (_powerLev > 2){
        _powerLev = 2;
    }
}

void Mario::damaged(int damage){
    if (_powerLev >= damage){
        _powerLev -= damage;
    }
    else{   // if (_powerLev == 0)
        if (_lives > 0){
            _dead = true;
        }
        else{   // if (_lives == 0)
            _gameOver = true;
        }
    }
}

void Mario::revive(){
    _lives -= 1;
    _powerLev = 0;
    _defeatStreak = 0;
    _dead = false;
}

// Mario moves in a random direction
void Mario::move(int dimension, FileProcessor* fileProcessor){
    fileProcessor->writeOutputFile("Mario will move ", false);
    switch (rand()%4){
        // move down ↓↓↓↓↓
        case 0:
            _position[0] += 1;
            if (_position[0] >= dimension){
                _position[0] = 0;
            }
            fileProcessor->writeOutputFile("DOWN.");
            break;
        // move up ↑↑↑↑↑
        case 1:
            _position[0] -= 1;
            if (_position[0] <= -1){
                _position[0] = dimension - 1;
            }
            fileProcessor->writeOutputFile("UP.");
            break;
        // move right →→→→→
        case 2:
            _position[1] += 1;
            if (_position[1] >= dimension){
                _position[1] = 0;
            }
            fileProcessor->writeOutputFile("RIGHT.");
            break;
        // move left ←←←←←
        case 3:
            _position[1] -= 1;
            if (_position[1] <= -1){
                _position[1] = dimension - 1;
            }
            fileProcessor->writeOutputFile("LEFT.");
            break;
    }
    fileProcessor->writeOutputFile("================");
}

void Mario::defeatEnemy(){
    _defeatStreak += 1;
    // - if Mario defeats 7 enemies on the same life, he earns another life.
    if (_defeatStreak == 7){
        _lives += 1;
        _defeatStreak = 0;
    }
}

void Mario::winGame(){
    _win = true;
}

void Mario::warp(){
    _warping = true;
}

bool Mario::isWarping(){
    return _warping;
}

bool Mario::isDead(){
    return _dead;
}

bool Mario::isGameOver(){
    return _gameOver;
}

bool Mario::isWon(){
    return _win;
}