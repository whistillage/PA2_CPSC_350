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
    myFileProcessor.readInputFile(argv[1]);

    if(!myFileProcessor.readSuccessful()){
        cout << "Reading input file unsuccessful. Exit Program." << endl;
    }
    
    World myWorld(myFileProcessor.getGameInfo());
    myWorld.printGameInfo();

    return 0;
}