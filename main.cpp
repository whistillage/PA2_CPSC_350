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

    FileProcessor* fileProcessor = new FileProcessor();

    // if failed to read input file, terminate the program.
    if(!fileProcessor->readFiles(argv[1], argv[2])){
        cout << "Failed to read files. Exit." << endl;
        return -2;
    }

    GameSimulator* gameSimulator = new GameSimulator();
    gameSimulator->initGame(fileProcessor->getGameInfo());

    fileProcessor->closeFiles();

    delete gameSimulator;
    delete fileProcessor;
    return 0;
}