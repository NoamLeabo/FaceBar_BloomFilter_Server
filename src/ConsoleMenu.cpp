#include "ConsoleMenu.h"
#include <iostream>
#include <sstream>

using namespace std;

ConsoleMenu::ConsoleMenu() {}

void ConsoleMenu::init(int initVals[])
{
    string input;
    int size, hash1, hash2;

    while (true)
    {
        // we get the user's input
        std::getline(std::cin, input);

        // Using stringstream to extract numbers from the input
        std::istringstream iss(input);
        // Try to extract three numbers as mentioned before
        if (iss >> size >> hash1 >> hash2)
        {
            // we save the vals in the initVals array and return it to the app
            initVals[0] = size;
            initVals[1] = hash1;
            initVals[2] = hash2;
            return;
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
                // we save the vals in the initVals array and return it to the app
                initVals[0] = size;
                initVals[1] = hash1;
                initVals[2] = -1;
                return;
            }
        }
    }
}

int ConsoleMenu::nextCommand()
{
    // we get from the user its next task
    int task;
    cin >> task;
    return task;
}