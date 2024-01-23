#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(){
    string input;
    string array_size;
    string hashfunc;
    string last_part;
    int array_size_int;
    int hashfunc_int;
    int last_part_int;

    cout<< "input numbers" << endl;
    std::getline(std::cin, input);;

    // This regular expression matches 3 numbers and avoids duplicates.
    // ex: 8 1 1 1 2 => 8, 1, 2. 
    regex regex_Multy_Digit("\\s*(\\d+)(\\s+(\\d+))+\\s+(\\d+)\\s?");
    regex regex_2Digit_input("(\\s*(\\d+))\\s+(\\d+)");
    smatch match;
    //If we got a proper input, we'll seperate the input for our apps use:  
    if (std::regex_search(input, match, regex_Multy_Digit))
    {
        array_size = match[1];
        hashfunc = match[3];
        last_part = match[4];
    }else if(std::regex_search(input, match, regex_2Digit_input )){
        array_size = match[1];
        hashfunc = match[2];
    }
    
    cout << "array size " << array_size <<endl;
    cout << "hash function " << hashfunc <<endl;
    cout << "last part idk what it is " << last_part <<endl;
    return 0;
}