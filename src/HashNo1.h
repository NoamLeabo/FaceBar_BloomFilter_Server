#ifndef HASHNO1_H
#define HASHNO1_H

#include "HashFunc.h"

using namespace std;

// hash function no. 1
class HashNo1 : public HashFunc {
public:
    // constructor
    HashNo1();

    // hash execution
    void hashing(string url);
    // get the hash value
    virtual size_t getValue();
};

#endif