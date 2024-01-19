#include <iostream>
#include "../src/BloomFilter.cpp"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
class FilterRunner{

    // check if url is int blacklist
    void checkinList(vector<string> list, string url){
        for (const auto &element : list){
            if (element == url){
                cout << "true" << endl;
                break;
            }
        }
        cout << "false" << endl;
    }
    int main(int argc, char const *argv[]){
        vector<string> urlList;
        // Declare variables to store the numbers
        int size, hash1, hash2 = 0, task;
        string url;
        // Read input from the user
        std::cin >> size >> hash1;

        // Check if there's a third number
        if (std::cin.peek() != '\n'){
            std::cin >> hash2;
        }
        BloomFilter filter = BloomFilter(size, hash1, hash2);

        cin >> task;
        getline(cin, url);
        // 1 add to BF. 2 search in BF
        while (true){
            switch (task){
            case 1:{
                filter.addUrl(url);
                urlList.push_back(url);
                break;
            }
            case 2:{
                bool check = filter.checkUrl(url);
                // if true need to check if false positive
                if (check)
                {
                    cout << "true ";
                    checkinList(urlList, url);
                }
                else
                    cout << "false" << endl;
                break;
            }
            // get new line if invalid input
            default:{
            }
            }
            cin >> task;
            getline(cin, url);
        }
        return 0;
    }
};