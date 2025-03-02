#ifndef WORLD_H // Header guard to prevent multiple inclusions
#define WORLD_H

#include "Level.h"
#include "FileProcessor.h"

class World {
    private:
        // pointer of, an array of game information
        int* _gameInfo;

        // array of, pointers of class 'Level'
        Level** _levels;

    public:
        // Constructor
        World(int gameInfo[]);

        // Destructor
        ~World();

        // call createLevel() and assign pointers of Levels, in _levels
        void createLevels();

        // create a class 'Level' and return its pointer
        // if it is the last stage, then create WITHOUT a warp, vice versa
        Level* createLevel(bool isLastStage);

        Level* getLevel(int levelNum);

        // print all levels
        void printLevels(FileProcessor* fileprocessor);

        // print the level of LevelNum, with mario in position[2]
        void printLevelwithMario(int LevelNum, int* position, FileProcessor* fileProcessor);
};

#endif // End of header guard