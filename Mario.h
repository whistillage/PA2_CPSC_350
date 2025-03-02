#ifndef MARIO_H // Header guard to prevent multiple inclusions
#define MARIO_H

#include <cstdlib>
#include <iostream>
#include "FileProcessor.h"
using namespace std;

class Mario {
    private:
        // dimension of the grid
        int _lives;

        // 20 coins = 1 life
        int _coins;

        // power level: 0, 1, or 2
        int _powerLev;

        // position of Mario in a level
        int _position[2];

        // # of enemies Mario defeated on the same life
        int _defeatStreak;

        // true when mario defeats the boss or encounters warp pipe
        bool _warping;

        // true when mario defeats the boss in the last stage
        bool _win;

        // true when get damage in state of power level 0 and life 0
        bool _gameOver;

        // true when get damage in state of power level 0
        bool _dead;

    public:
        // Constructor
        Mario(int lives);

        // Destructor
        ~Mario();

        // set Mario in a random position
        void setRandPosition(int dimension, FileProcessor* fileProcessor, int curLevelNum);

        // get _position[2]
        int* getPosition();

        // get _powerLev
        int getPowerLev();

        // get _lives
        int getLives();

        // get _coins
        int getCoins();

        // increase _coins by 1
        void increaseCoins();

        // increase _powerLev by 1
        void increasePowerLev();

        // if mario loses to Goomba, Koopa, or Boss
        void damaged(int damage);

        void revive();

        // Mario moves in a random direction
        void move(int dimension, FileProcessor* fileProcessor);

        void defeatEnemy();

        void winGame();

        void warp();

        bool isWarping();

        bool isDead();

        bool isGameOver();

        bool isWon();
};

#endif // End of header guard