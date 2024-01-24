#include "App.h"
#include "AddUrl.h"
#include "CheckUrl.h"
#include <iostream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include "ConsoleMenu.h"

using namespace std;

// constructor
App::App(vector<HashFunc *> funcBank) : funcBank(funcBank), bF(0, 1, funcBank), numOfCommands(0), commands()
{
}

// adding a command to the app's commands map
void App::addCommand(int index, ICommandable *command)
{
    // we add to the command another app by index
    this->commands[index] = command;
    // updating the current Num of commands we have so far
    this->numOfCommands++;
}

// we run the app
void App::run()
{
    // we set a consoleMenu
    ConsoleMenu menu;

    // an array of the 3 vars for the initialize of the BF
    int initVals[3];
    // we insert the vals via our menu
    menu.init(initVals);

    // if we have only 2 args (0 and 1) it means we have only 1 HF
    if (initVals[2] == -1)
    {
        // we build our BF accordingly
        bF = BloomFilter(initVals[0], initVals[1], this->funcBank);
        // we set a new commandable and attach it to our new BF
        AddUrl add(&bF);
        addCommand(1, &add);
        // we set a new commandable and attach it to our new BF
        CheckUrl check(&bF);
        addCommand(2, &check);
    }
    else
    // if we get to this block it means we have only 3 args and we have 2 HF
    {
        // we build our BF accordingly
        bF = BloomFilter(initVals[0], initVals[1], initVals[2], this->funcBank);
        // we set a new commandable and attach it to our new BF
        AddUrl add(&bF);
        addCommand(1, &add);
        // we set a new commandable and attach it to our new BF
        CheckUrl check(&bF);
        addCommand(2, &check);
    }

    // commandVals - the user's command and url for us to deal with
    string commandVals[2];
    int task;
    while (true)
    {
        // task - the user's task and input
        menu.nextCommand(commandVals);
        task = stoi(commandVals[0]);
        // performing the given task by executing its action
        this->commands[task]->execute(commandVals[1]);
    }
}