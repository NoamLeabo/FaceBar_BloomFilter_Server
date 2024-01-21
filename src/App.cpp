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

using namespace std;
App::App() : bF(0, 1), numOfCommands(0), commands() {
    AddUrl add(&this->bF);
    addCommand(1, &add);
    CheckUrl check(&this->bF);
    addCommand(2, &check);
}


void App::addCommand(int index, ICommandable* command){
    // we add to the command another app
   this->commands[index] = command;
   // updating the current Num of commands we have so far
   this->numOfCommands++;
}

void App::run() {
    string input;
    int size, hash1, hash2, task;

    while (true)
    {
        std::getline(std::cin, input);
    
        // Using stringstream to extract numbers from the input
        std::istringstream iss(input);
        // Try to extract three numbers
        if (iss >> size >> hash1 >> hash2)
        {
            // Numbers extracted successfully
            bF = BloomFilter(size, hash1, hash2);
            break;
        }
        else
        {
            // Clear the stringstream's error flags
            iss.clear();

            // If extraction fails, try to extract two numbers
            iss.seekg(0);
            if (iss >> size >> hash1)
            {
                bF = BloomFilter(size, hash1);
                break;
            }
        }
    }

    string url;
    cin >> task;
    getline(cin, url);
    // 1 add to BF. 2 search in BF
    while (true)
    {
        this->commands[task]->execute(url);
        cin >> task;
        getline(cin, url);
    }
}