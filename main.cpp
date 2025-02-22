#include "FileProcessor.h"
#include "World.h"
using namespace std;

int main(int argc, char* argv[]){
    /*
    argv[1]: input file name
    argv[2]: output file name
    */
    if (argc != 3){
        cout << "Invalid Arguments!!";
        return -1;
    }

    FileProcessor myFileProcessor;

    // if reading input file failed, terminate the program.
    if(!myFileProcessor.readInputFile(argv[1])){
        cout << "Reading input file unsuccessful. Exit Program." << endl;
        return -2;
    }
    
    World myWorld(myFileProcessor.getGameInfo());
    myWorld.createLevels();

    return 0;
}