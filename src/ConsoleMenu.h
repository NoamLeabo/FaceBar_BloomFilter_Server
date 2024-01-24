#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H
#include <string>
#include <vector>

using namespace std;
class ConsoleMenu
{
private:
    void removeDuplicates(std::vector<int> &vec);
    bool validateIntVector(const std::vector<int> &vec);

public:
    ConsoleMenu();
    void init(int initVals[]);
    string *nextCommand(string commandVals[]);
};

#endif