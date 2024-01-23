#include "HashNo2.h"
#include <string>
using namespace std;

// constuctor
HashNo2::HashNo2() {}

// hashing the given URL and storing the result in the var - i_hashed_value
void HashNo2::hashing(string url)
{
    size_t hashed = std::hash<string>()(url);
    hashed = std::hash<string>()(to_string(hashed));
    this->i_hashed_value = hashed;
}

// return the hashed value
size_t HashNo2::getValue()
{
    return this->i_hashed_value;
}