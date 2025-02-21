#ifndef FILEPROCESSOR_H // Header guard to prevent multiple inclusions
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileProcessor {
    private:
        int _gameInfo[8];
    public:
        // Default Constructor
        FileProcessor();

        // Destructor
        ~FileProcessor();

        // save gameInfo from inputFile
        // return if input file was read successfully
        bool readInputFile(const char* inputFile);

        int* getGameInfo();
};

#endif // End of header guard