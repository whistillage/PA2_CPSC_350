#include "Mario.h"

// Constructor
Mario::Mario(int dimension, int lives){
    _lives = lives;
    _coins = 0;
    _powerLev = 0;
    setRandPosition(dimension);
}

// Destructor
Mario::~Mario(){
}

void Mario::setRandPosition(int dimension){
    _position[0] = rand() % (dimension);
    _position[1] = rand() % (dimension);
}

int* Mario::getPosition(){
    return _position;
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

// Mario moves in a random direction
void Mario::move(int dimension){
    switch (rand()%4){
        // move right →→→→→
        case 0:
            _position[0] += 1;
            if (_position[0] >= dimension){
                _position[0] = 0;
            }
            break;
        // move left ←←←←←
        case 1:
            _position[0] -= 1;
            if (_position[0] <= -1){
                _position[0] = dimension - 1;
            }
            break;
        // move down ↓↓↓↓↓
        case 2:
            _position[1] += 1;
            if (_position[1] >= dimension){
                _position[1] = 0;
            }
            break;
        // move up ↑↑↑↑↑
        case 3:
            _position[1] -= 1;
            if (_position[1] <= -1){
                _position[1] = dimension - 1;
            }
            break;
    }
}