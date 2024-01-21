#include "App.h"
#include <iostream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
App::App() : bloomFilter(0, 1){
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
            bloomFilter = BloomFilter(size, hash1, hash2);
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
                bloomFilter = BloomFilter(size, hash1);
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
        switch (task)
        {
            case 1:
            {
                bloomFilter.addUrl(url);
                break;
            }
            case 2:
            {
                bool check = bloomFilter.checkFunc(url);
                // if true need to check if false positive
                if (check)
                {
                    cout << "true ";
                    bool check = bloomFilter.blacklistCheck(url);
                    if (check)
                    {
                        cout << "true" << endl;
                    }
                    else
                    cout << "false" << endl;
                }
                else
                    cout << "false" << endl;
                break;
            }
                // get new line if invalid input
            default:
            {
            }
        }
        cin >> task;
        getline(cin, url);
    }
}