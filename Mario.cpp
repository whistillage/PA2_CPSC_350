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
void Mario::move(){
    switch (rand()%4){
        // move right →→→→→
        case 0:
            _position[0] += 1;
            break;
        // move left ←←←←←
        case 1:
            _position[0] -= 1;
            break;
        // move up ↑↑↑↑↑
        case 2:
            _position[1] += 1;
            break;
        // move down ↓↓↓↓↓
        case 3:
            _position[1] -= 1;
            break;
    }
}