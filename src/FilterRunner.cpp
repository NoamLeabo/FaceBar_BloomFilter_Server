#include <iostream>
#include "../src/BloomFilter.cpp"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class FilterRunner
{
    int main(int argc, char const *argv[])
    {
        std::string input;

        int size, hash1, hash2, task;
        BloomFilter *filter;

        while (true)
        {
            std::getline(std::cin, input);
            // Using stringstream to extract numbers from the input
            std::istringstream iss(input);
            // Try to extract three numbers
            if (iss >> size >> hash1 >> hash2)
            {
                // Numbers extracted successfully
                filter = new BloomFilter(size);
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
                    filter = new BloomFilter(size, hash1);
                    break;
                }
            }
        }

        string url;
        cin >> task;
        getline(cin, url);
        cout << task << endl;
        cout << url << endl;
        // 1 add to BF. 2 search in BF
        while (true)
        {
            switch (task)
            {
            case 1:
            {
                filter->addUrl(url);
                break;
            }
            case 2:
            {
                bool check = filter->checkFunc(url);
                // if true need to check if false positive
                if (check)
                {
                    cout << "true - ";
                    bool check = filter->blacklistCheck(url);
                    cout << check << endl;
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
        return 0;
    }
};