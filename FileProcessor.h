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
        
    public:
        // Constructor
        FileProcessor();

        // Destructor
        ~FileProcessor();

        // read gameInfo from inputFile
        // return if input file was read successfully
        bool readInputFile(const char* inputFile);

        // return the pointer of _gameInfo
        int* getGameInfo();
};

#endif // End of header guard