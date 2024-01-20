#ifndef HASHNO2_H
#define HASHNO2_H

#include "HashFunc.h"

using namespace std;

class HashNo2 : public HashFunc {
    public:
        void hashing(string url);
        virtual size_t getValue();
};

#endif
