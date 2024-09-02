#ifndef ICOMMANDABLE_H
#define ICOMMANDABLE_H

#include <string>
#include <map>

using namespace std;

// interface for commandable classes
class ICommandable {
public:
    // execute the command
    virtual bool execute(string url) = 0;
};

#endif