#ifndef MARIO_H // Header guard to prevent multiple inclusions
#define MARIO_H

#include <cstdlib>
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

        // true when get damage in state of power level 0
        bool _dead;

        // true when get damage in state of power level 0 and life 0
        bool _gameOver;
    public:
        // Constructor
        Mario(int dimension, int lives);

        // Destructor
        ~Mario();

        // set _position[2] into [xPos, yPos]
        void setRandPosition(int dimension);

        // get _position[2]
        int* getPosition();

        // increase _coins by 1
        void increaseCoins();

        // increase _powerLev by 1
        void increasePowerLev();

        // when mario loses to Goomba or Koopa
        void getDamage();

        void newLife();

        // Mario moves in a random direction
        void move(int dimension);

        bool isDead();

        bool isGameOver();
};

#endif // End of header guard