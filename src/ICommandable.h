#ifndef MYCLASS_H
#define MYCLASS_H
#include <string>
#include <map>

using namespace std;

class ICommandable {
    public:
        virtual void execute() = 0;
};

#endif