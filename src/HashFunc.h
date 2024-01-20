#ifndef HASHFUNC_H
#define HASHFUNC_H
#include <string>
#include <map>

using namespace std;

class HashFunc
{
protected:
    size_t i_hashed_value;

public:
    virtual void hashing(string url) = 0;
    virtual size_t getValue() = 0;
};

#endif