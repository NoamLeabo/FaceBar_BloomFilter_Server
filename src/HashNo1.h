#ifndef HASHNO1_H
#define HASHNO1_H

#include "HashFunc.h"

using namespace std;

class HashNo1 : public HashFunc {
public:
    HashNo1();

    void hashing(string url);

    virtual size_t getValue();
};

#endif