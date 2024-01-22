#ifndef APP_H
#define APP_H
#include <string>
#include <map>
#include "BloomFilter.h"
#include "ICommandable.h"


class App
{
private:
    map<int, ICommandable *> commands;
    BloomFilter bF;
    vector<HashFunc*> funcBank;
    int numOfCommands;

public:
    App(vector<HashFunc*> funcBank);
    void run();
    void addCommand(int index, ICommandable *command);
};

#endif