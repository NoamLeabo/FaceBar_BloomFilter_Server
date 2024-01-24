#include "HashNo1.h"
#include <string>

using namespace std;

// constructor
HashNo1::HashNo1() {}

// hashing the given URL and storing the result in the var - i_hashed_value
void HashNo1::hashing(string url) {
    size_t hashed = std::hash<string>()(url);
    this->i_hashed_value = hashed;
}

// return the hashed value
size_t HashNo1::getValue() {
    return this->i_hashed_value;
}