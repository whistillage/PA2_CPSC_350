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