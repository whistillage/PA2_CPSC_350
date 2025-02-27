#include "FileProcessor.h"

// Constructor
FileProcessor::FileProcessor() {
}

// Destructor
FileProcessor::~FileProcessor() {
}

// read gameInfo from inputFile
// return if input file was read successfully
/* Input File Format:
    Line # 1 is the number of levels, L (a positive integer)
    Line # 2 is the dimension of the grid, N (a positive integer)
    Line # 3 is the number of initial lives, V (a positive integer)
    Line # 4 is the approximate percentage of the positions in each level with coins (a positive integer)
    Line # 5 is the approximate percentage of the positions in each level with nothing (a positive integer)
    Line # 6 is the approximate percentage of the positions in each level with Goombas (a positive integer)
    Line # 7 is the approximate percentage of the positions in each level with Koopas (a positive integer)
    Line # 8 is the approximate percentage of the positions in each level with mushrooms (a positive integer)
*/
bool FileProcessor::readFiles(const char* inputFile, const char* outputFile){
    _inFile.open(inputFile);
    _outFile.open(outputFile);

    // if failed to read input file, return false
    if (!_inFile.is_open()){
        cout << "Error opening input file!!" << endl;
        return false;
    }
    // if failed to read output file, return false
    if (!_outFile.is_open()){
        cout << "Error opening output file!!" << endl;
        return false;
    }
    
    // read lines from input file
    for (int i = 0; i < 8; i++){
        string line;
        getline(_inFile, line);
        _gameInfo[i] = stoi(line);
    }
    
    return true;
}

void FileProcessor::closeFiles(){
    _inFile.close();
    _outFile.close();
}

// return the pointer of _gameInfo
int* FileProcessor::getGameInfo(){
    return _gameInfo;
}