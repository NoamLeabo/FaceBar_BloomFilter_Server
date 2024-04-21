#include "ConsoleMenu.h"
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

ConsoleMenu::ConsoleMenu() {}

bool ConsoleMenu::validateIntVector(const std::vector<int> &vec) {
    // we check that we didn't get any HF which is not 1 or 2
    // if we didn't get any num except the array size we return error
    if (vec.size() < 2) {
        return false;
    }
    // check the int value
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] != 1 && vec[i] != 2) {
            return false;
        }
    }
    return true;
}

void ConsoleMenu::removeDuplicates(std::vector<int> &vec) {
    // removing any duplicates
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

void ConsoleMenu::init(int initVals[]) {
    // we set a new vector to store the input
    std::vector<int> result;
    // a string to get the user's input
    std::string input;

    while (true) {
        // Read a line from user input
        std::getline(std::cin, input);
        // ints extractor
        std::istringstream iss(input);
        int number;
        // while we manage to read an int we push it to the vector
        while (iss >> number) {
            result.push_back(number);
        }

        // Check if there was any invalid input
        if (!iss.eof()) {
            result.clear(); // Clear the vector in case of invalid input
        } else {
            // now we check that except the array size we didn't get any
            // num which is not 1 or 2
            if (validateIntVector(result)) {
                // remove any duplicates in the vector
                removeDuplicates(result);
                // we separate for 2 cases

                // we have 2 HashFunc to work with
                if (result.size() == 3) {
                    // array size
                    initVals[0] = result.at(2);
                    // HF No. 1
                    initVals[1] = result.at(1);
                    // HF No. 2
                    initVals[2] = result.at(0);
                    return;
                }
                    // we have 1 HashFunc to work with
                else {
                    // array size
                    initVals[0] = result.at(1);
                    // HF No. 1
                    initVals[1] = result.at(0);
                    initVals[2] = -1;
                    return;
                }
            } else
                // we start over
                result.clear();
        }
    }
}

string *ConsoleMenu::nextCommand(string commandVals[]) {
    // input - the user input
    string input;
    while (true) {
        // we get the user's inpur
        std::getline(std::cin, input);
        // a REGEX pattern for - *int 1 or 2**space**string*
        regex regex_Multy_Digit("(^|\n)\\s*([1-2])\\s+([^\\s]*)\\s?");
        smatch match;
        // if we have a match we return it
        if (std::regex_search(input, match, regex_Multy_Digit)) {
            // the task
            commandVals[0] = (string) match[2];
            // the url string
            commandVals[1] = (string) match[3];
            return commandVals;
        }
    }
}

void ConsoleMenu::initFromBuff(int initVals[3], string buff) {
    // we set a new vector to store the input
    std::vector<int> result;
    // ints extractor
    std::istringstream iss(buff);
    int number;
    // while we manage to read an int we push it to the vector
    while (iss >> number) {
        result.push_back(number);
    }

    // Check if there was any invalid input
    if (!iss.eof()) {
        result.clear(); // Clear the vector in case of invalid input
    } else {
        // now we check that except the array size we didn't get any
        // num which is not 1 or 2
        if (validateIntVector(result)) {
            // remove any duplicates in the vector
            removeDuplicates(result);
            // we separate for 2 cases

            // we have 2 HashFunc to work with
            if (result.size() == 3) {
                // array size
                initVals[0] = result.at(2);
                // HF No. 1
                initVals[1] = result.at(1);
                // HF No. 2
                initVals[2] = result.at(0);
                return;
            }
                // we have 1 HashFunc to work with
            else {
                // array size
                initVals[0] = result.at(1);
                // HF No. 1
                initVals[1] = result.at(0);
                initVals[2] = -1;
                return;
            }
        } else
            // we start over
            result.clear();
    }
}