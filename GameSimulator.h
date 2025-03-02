#ifndef GAMESIMULATOR_H // Header guard to prevent multiple inclusions
#define GAMESIMULATOR_H

#include "World.h"
#include "Mario.h"
#include "FileProcessor.h"
using namespace std;

class GameSimulator {
    private:
        // current Level Number
        int _curLevelNum;

        // array of game information
        int _gameInfo[8];

        int _moveCount;

    public:
        // Constructor
        GameSimulator();

        // Destructor
        ~GameSimulator();

        // if win, return 1
        // if gameover, return 0
        void initGame(const char* inputFile, const char* outputFile);

        // if win, return 1
        // if gameover, return 0
        int playGame(FileProcessor* fileProcessor);

        void marioInteraction(Mario* mario, World* world, FileProcessor* fileProcessor);
};

#endif // End of header guard