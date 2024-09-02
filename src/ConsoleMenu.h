#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H

#include <string>
#include <vector>

using namespace std;

// console menu class
class ConsoleMenu {
private:
    // remove duplicates from a vector
    void removeDuplicates(std::vector<int> &vec);

    // validate integers rang in a vector
    bool validateIntVector(const std::vector<int> &vec);

public:
    // constructor
    ConsoleMenu();

    // initialize the menu
    void init(int initVals[]);
    
    // get the next command
    string *nextCommand(string commandVals[]);

    // initialize the menu from a buffer
    void initFromBuff(int initVals[3], string buff);
};

#endif