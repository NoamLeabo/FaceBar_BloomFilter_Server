#include "HashNo1.h"
#include <string>
using namespace std;

HashNo1::HashNo1() {}

void HashNo1::hashing(string url)
{
    size_t hashed = std::hash<string>()(url);
    this->i_hashed_value = hashed;
}
size_t HashNo1::getValue()
{
    return this->i_hashed_value;
}