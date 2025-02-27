#include "FileProcessor.h"
#include "World.h"
#include "GameSimulator.h"
using namespace std;

int main(int argc, char* argv[]){
    /*
    argv[1]: input file name
    argv[2]: output file name
    */
    if (argc != 3){
        cout << "Invalid Arguments. Exit.";
        return -1;
    }

    GameSimulator* gameSimulator = new GameSimulator();
    gameSimulator->initGame(argv[1], argv[2]);
    delete gameSimulator;
    return 0;
}