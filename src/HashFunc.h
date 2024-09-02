#ifndef HASHFUNC_H
#define HASHFUNC_H

#include <string>
#include <map>

using namespace std;

class HashFunc {
protected:
    // the hashed value
    size_t i_hashed_value;

public:
    // hash execution
    virtual void hashing(string url) = 0;
    // get the hash value
    virtual size_t getValue() = 0;
};

#endif