#include "HashNo1.h"
#include <string>
using namespace std;

HashNo1::HashNo1(){}

void HashNo1:: hashing(string url){
    size_t hashed = std::hash<string>()(url);
    this->s_hashed_value = hashed;
    this->i_hashed_value = hashed;
}