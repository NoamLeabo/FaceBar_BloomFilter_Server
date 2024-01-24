#ifndef ICOMMANDABLE_H
#define ICOMMANDABLE_H
#include <string>
#include <map>

using namespace std;

class ICommandable
{
public:
    virtual void execute(string url) = 0;
};

#endif