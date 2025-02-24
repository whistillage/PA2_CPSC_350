#ifndef MARIO_H // Header guard to prevent multiple inclusions
#define MARIO_H

using namespace std;

class Mario {
    private:
        // dimension of the grid
        int _lives;

        // 20 coins = 1 life
        int coins = 0;

        // power level: 0, 1, or 2
        int power_lev = 0;
    public:
        // Constructor
        Mario(int lives);

        // Destructor
        ~Mario();
};

#endif // End of header guard