// AUTHOR INFO
// Full Name: Taehyun Kim (with Danica)
// Student ID: 2484228
// Chapman Email: taehykim@chapman.edu
// Course Number & Section: CPSC-350-01
// Assignment Number: PA 2: Not so Super Mario Bros.
#include "FileProcessor.h"

// Constructor
FileProcessor::FileProcessor() {
}

// Destructor
FileProcessor::~FileProcessor() {
}

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
// assign input data -> gameInfo
// return true if files were read successfully
bool FileProcessor::readFiles(const char* inputFile, const char* outputFile, int* gameInfo){
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
        gameInfo[i] = stoi(line);
    }
    
    return true;
}

void FileProcessor::writeOutputFile(string text, bool newline){
    if (newline){
        _outFile << text << endl;
    }
    else{
        _outFile << text;
    }
}

void FileProcessor::closeFiles(){
    _inFile.close();
    _outFile.close();
}