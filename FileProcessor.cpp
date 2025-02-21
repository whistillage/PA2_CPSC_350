#include "FileProcessor.h"
#include "World.h"

// Default Constructor: Allocates memory
FileProcessor::FileProcessor() {
}

// Destructor: Frees the memory allocated
FileProcessor::~FileProcessor() {
}

void FileProcessor::readInputFile(const char* inputFile){
    /*
    Line # 1 is the number of levels, L (a positive integer)
    Line # 2 is the dimension of the grid, N (a positive integer)
    Line # 3 is the number of initial lives, V (a positive integer)
    Line # 4 is the approximate percentage of the positions in each level with coins (a positive integer)
    Line # 5 is the approximate percentage of the positions in each level with nothing (a positive integer)
    Line # 6 is the approximate percentage of the positions in each level with Goombas (a positive integer)
    Line # 7 is the approximate percentage of the positions in each level with Koopas (a positive integer)
    Line # 8 is the approximate percentage of the positions in each level with mushrooms (a positive integer)
    
    Values on line 4-8 MUST sum to 100.
    */
    ifstream inFile(inputFile);
    if (!inFile.is_open()){
        cout << "Error opening input file!!" << endl;
        return;
    }

    // mark that the file is read successfully.
    _isSucceed = 1;
    
    for (int i = 0; i < 8; i++){
        string line;
        getline(inFile, line);
        _gameInfo[i] = stoi(line);
    }
    inFile.close();
}

bool FileProcessor::readSuccessful(){
    return _isSucceed;
}

int* FileProcessor::getGameInfo(){
    return _gameInfo;
}