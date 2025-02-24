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

        void increasePowerLev();

        // Mario moves in a random direction
        void move(int dimension);
};

#endif // End of header guard