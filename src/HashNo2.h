#ifndef HASHNO2_H
#define HASHNO2_H

#include "HashFunc.h"

using namespace std;

// hash function no. 2
class HashNo2 : public HashFunc {
public:
    // constructor
    HashNo2();

    // hash execution
    void hashing(string url);
    // get the hash value
    virtual size_t getValue();
};

#endif
