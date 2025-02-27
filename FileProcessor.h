#ifndef FILEPROCESSOR_H // Header guard to prevent multiple inclusions
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileProcessor {
    private:
        // array of game information
        int _gameInfo[8];

        // variable for input File
        ifstream _inFile;

        // variable for output File
        ofstream _outFile;
        
    public:
        // Constructor
        FileProcessor();

        // Destructor
        ~FileProcessor();

        // read gameInfo from inputFile
        // return true if files were read successfully
        bool readFiles(const char* inputFile, const char* outputFile);

        void closeFiles();

        // return the pointer of _gameInfo
        int* getGameInfo();
};

#endif // End of header guard