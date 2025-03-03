// AUTHOR INFO
// Full Name: Taehyun Kim (with Danica)
// Student ID: 2484228
// Chapman Email: taehykim@chapman.edu
// Course Number & Section: CPSC-350-01
// Assignment Number: PA 2: Not so Super Mario Bros.
#ifndef MARIO_H // Header guard to prevent multiple inclusions
#define MARIO_H

#include "FileProcessor.h"

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

        // # of Mario's moves
        int _moveCount;

        // true when mario defeats the boss or encounters warp pipe
        bool _warping;

        // true when mario defeats the boss in the last stage
        bool _win;

        // true when get damage in state of power level 0 and life 0
        bool _gameOver;

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

        // get _moveCount
        int getMoveCount();

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

        bool isGameOver();

        bool isWon();
};

#endif // End of header guard