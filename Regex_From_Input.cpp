#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(){
    string input;
    string array_size;
    string hashfunc;
    string second_hashfunc;
    int array_size_int;
    int hashfunc_int;
    int second_hashfunc_int;

    cout<< "input numbers" << endl;
    std::getline(std::cin, input);;

    // This regular expression matches 3 or 2 numbers and avoids duplicates.
    // ex: 8 1 1 1 2 => 8, 1, 2. 
    regex regex_Multy_Digit("(^|\n)\\s*(\\d+)(((\\s+(1))+(\\s+(2))?)|((\\s+(2))+(\\s+(1))?))\\s?");
    smatch match;

    //If we got a proper input, we'll seperate the input for our apps use:  
    if (std::regex_search(input, match, regex_Multy_Digit))
    {
        array_size = match[2];
        cout<< "match 1: " << match[2] << endl;

        cout<< "match 5: " << match[6] << endl;
        cout<< "match 7: " << match[8] << endl;

        cout<< "match 10: " <<match[11] << endl;
        cout<< "match 12: " <<match[13] << endl;

        if(((string)match[6]).empty()){
            hashfunc = match[11];
            if (!((string)match[13]).empty())
            {
                second_hashfunc = match[13];
            }
        }else{
            hashfunc = match[6];
            if (!((string)match[8]).empty())
            {
                second_hashfunc = match[8];
            }
        }
    }

    cout << "array size " << array_size <<endl;
    cout << "hash function " << hashfunc <<endl;
    cout << "last part idk what it is " << second_hashfunc <<endl;
    return 0;
}


