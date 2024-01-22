#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(){
    string input;
    string array_size;
    string hashfunc;
    string last_part;

    cout<< "input numbers" << endl;
    std::getline(std::cin, input);;

    // This regular expression matches 3 numbers and avoids duplicates.
    // ex: 8 1 1 1 2 => 8, 1, 2. 
    regex regex("\\s*(\\d+)(\\s+(\\d+))+\\s+(\\d+)\\s?");
    smatch match;
    //If we got a proper input, we'll seperate the input for our apps use:  
    if (std::regex_search(input, match, regex))
    {
        array_size = match[1];
        hashfunc = match[3];
        last_part = match[4];
    }
    cout << "array size " << array_size <<endl;
    cout << "hash function " << hashfunc <<endl;
    cout << "last part idk what it is " << last_part <<endl;
    return 0;
}