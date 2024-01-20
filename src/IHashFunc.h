#ifndef IHASHFUNC_H
#define IHASHFUNC_H
#include "ICommandable.h"
#include <string>
#include <map>

using namespace std;

class IHashFunc : public ICommandable {
    public:
        virtual int hashing(string url) = 0;
};

#endif