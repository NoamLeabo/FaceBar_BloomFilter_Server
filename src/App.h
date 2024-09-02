#ifndef APP_H
#define APP_H

#include <string>
#include <map>
#include "BloomFilter.h"
#include "ICommandable.h"

// App class
class App {
private:
    // app's commands
    map<int, ICommandable *> commands;
    // app's bloom filter
    BloomFilter* bF;
    // app's hash functions
    vector<HashFunc *> funcBank;
    // number of commands
    int numOfCommands;

public:
    // constructor
    App(vector<HashFunc *> funcBank);

    // run the app
    void run();

    // add a command
    void addCommand(int index, ICommandable *command);

    // get whether the bloom filter is initialized 
    bool bFInitialized();

    // set the bloom filter to initialized
    void setBFInit();

    // get the bloom filter
    BloomFilter *getBF();
    
    // perform a command
    bool doCommand(int task, string url);

    // get the hash functions
    vector<HashFunc *> getFuncBank();

    // set the bloom filter
    void setBF(BloomFilter* bF);
};

#endif