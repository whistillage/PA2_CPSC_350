#include "Mario.h"

// Constructor
Mario::Mario(int lives){
    _lives = lives;
}

// Destructor
Mario::~Mario(){
}

void Mario::setPosition(int xPos, int yPos){
    _position[0] = xPos;
    _position[1] = yPos;
}

int* Mario::getPosition(){
    return _position;
}

// increase _coins by 1
void Mario::increaseCoins(){
    _coins += 1;
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