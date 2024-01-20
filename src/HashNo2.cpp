#include "HashNo2.h"
#include <string>
using namespace std;

HashNo2::HashNo2(){}

void HashNo2:: hashing(string url){
    size_t hashed = std::hash<string>()(url);
    size_t hashed = std::hash<string>()(to_string(hashed));
    this->i_hashed_value = hashed;
}
size_t HashNo2::getValue(){
    return this->i_hashed_value;
}