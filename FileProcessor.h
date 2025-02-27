#ifndef FILEPROCESSOR_H // Header guard to prevent multiple inclusions
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileProcessor {
    private:
        // variable for input File
        ifstream _inFile;

        // variable for output File
        ofstream _outFile;
        
    public:
        // Constructor
        FileProcessor();

        // Destructor
        ~FileProcessor();

        // assign input data -> gameInfo
        // return true if files were read successfully
        bool readFiles(const char* inputFile, const char* outputFile, int* gameInfo);

        void writeOutputFile(string text);

        // close inputFile and outputFile
        void closeFiles();
};

#endif // End of header guard