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

    FileProcessor myFileProcessor;

    // if failed to read input file, terminate the program.
    if(!myFileProcessor.readInputFile(argv[1])){
        cout << "Failed to read input file. Exit." << endl;
        return -2;
    }

    GameSimulator myGameSimulator;
    myGameSimulator.initGame(myFileProcessor.getGameInfo());

    return 0;
}