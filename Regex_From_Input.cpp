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
    regex regex_Multy_Digit("\\s*(\\d+)(((\\s+(1))+(\\s+(2))?)|((\\s+(2))+(\\s+(1))?))\\s?");
    smatch match;

    //If we got a proper input, we'll seperate the input for our apps use:  
    if (std::regex_search(input, match, regex_Multy_Digit))
    {
        array_size = match[1];
        cout<< "match 1: " << match[1] << endl;

        cout<< "match 5: " << match[5] << endl;
        cout<< "match 7: " << match[7] << endl;

        cout<< "match 10: " <<match[10] << endl;
        cout<< "match 12: " <<match[12] << endl;

        if(((string)match[5]).empty()){
            hashfunc = match[10];
            if (!((string)match[12]).empty())
            {
                second_hashfunc = match[12];
            }
        }else{
            hashfunc = match[5];
            if (!((string)match[7]).empty())
            {
                second_hashfunc = match[7];
            }
        }
    }

    cout << "array size " << array_size <<endl;
    cout << "hash function " << hashfunc <<endl;
    cout << "last part idk what it is " << second_hashfunc <<endl;
    return 0;
}
