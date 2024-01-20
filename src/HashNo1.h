#ifndef HASHNO1_H
#define HASHNO1_H

#include "HashFunc.h"

using namespace std;

class HashNo1 : public HashFunc
{
public:
    void hashing(string url);
    virtual size_t getValue();
};

#endif