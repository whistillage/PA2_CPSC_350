#ifndef FILEPROCESSOR_H // Header guard to prevent multiple inclusions
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileProcessor {
    private:
        int _gameInfo[8];
        int _isSucceed = 0;
    public:
        // Default Constructor
        FileProcessor();

        // Destructor
        ~FileProcessor();

        // get gameInfo from inputFile
        void readInputFile(const char* inputFile);

        bool readSuccessful();

        int* getGameInfo();
};

#endif // End of header guard