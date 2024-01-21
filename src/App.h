#ifndef APP_H
#define APP_H
#include <string>
#include <map>
#include "BloomFilter.h"
#include "ICommandable.h"

class App
{
private:
    BloomFilter bF;
    map<int, ICommandable *> commands;
    int numOfCommands;

public:
    App();
    void run();
    void addCommand(int index, ICommandable *command);
};

#endif