AUTHOR INFO
Full Name: Taehyun Kim (with Danica)
Student ID: 2484228
Chapman Email: taehykim@chapman.edu
Course Number & Section: CPSC-350-01
Assignment Number: PA 2: Not so Super Mario Bros.

SOURCE FILES
e.exe
FileProcessor.cpp
FileProcessor.h
GameSimulator.cpp
GameSimulator.h
input.txt
Level.cpp
Level.h
main.cpp
Mario.cpp
Mario.h
output.txt
README.md
World.cpp
World.h

ERRORS
A description of any known compile or runtime errors, code limitations, or deviations from the assignment specification (if applicable)
Mario consumes mushroom even if he is in state of PO2.
If Mario dies, he loses all of his coins.
The total number of moves do not include warps(when mario goes to next level).

REFERENCES
A list of all references used to complete the assignment, including peers (if applicable)
NA

RUNNING INSTRUCTIONS
g++ *.cpp -o e.exe
./e.exe input.txt output.txt
