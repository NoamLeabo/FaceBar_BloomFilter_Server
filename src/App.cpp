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

// constructor
App::App() : bF(0, 1), numOfCommands(0), commands()
{
    // we add the 'Add' and 'Check' URL commands to our app
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
    // input - user intput
    string input;
    // we'll try to get: size - BF bits size, hash1,2 - which HF the user wants to use
    int size, hash1, hash2;
    // the program starts
    while (true)
    {
        // we get the user's input
        std::getline(std::cin, input);

        // Using stringstream to extract numbers from the input
        std::istringstream iss(input);
        // Try to extract three numbers as mentioned before
        if (iss >> size >> hash1 >> hash2)
        {
            // Numbers extracted successfully and so we build the BF accordingly
            bF = BloomFilter(size, hash1, hash2);
            AddUrl add(&bF);
            addCommand(1, &add);
            CheckUrl check(&bF);
            addCommand(2, &check);
            break;
        }
        else
        // Numbers hasn't been extracted successfully
        {
            // Clear the stringstream's error flags
            iss.clear();

            // extraction failed, now we try to extract only two numbers
            iss.seekg(0);
            if (iss >> size >> hash1)
            {
                // Numbers extracted successfully and so we build the BF accordingly
                bF = BloomFilter(size, hash1);
                AddUrl add(&bF);
                addCommand(1, &add);
                CheckUrl check(&bF);
                addCommand(2, &check);
                break;
            }
        }
    }

    // task - the user's task
    int task;
    // url - the user's url
    string url;
    // getting the input
    cin >> task;
    getline(cin, url);

    while (true)
    {
        // performing the given task by executing its action
        // Check if the key exists in the commands map
        if (commands.find(task) != commands.end())
        {
            // performing the given task by executing its action
            this->commands[task]->execute(url);
        }
        else
        {
            // Handle the case where the key is not found (invalid task)
            cout << "Invalid task: " << task << endl;
        }
        // and getting another input from the user
        cin >> task;
        getline(cin, url);
    }
}