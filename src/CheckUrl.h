#ifndef CHECKURL_H
#define CHECKURL_H

#include <string>
#include <map>
#include "ICommandable.h"
#include "BloomFilter.h"

using namespace std;

// CheckUrl class
class CheckUrl : public ICommandable {
private:
    // bloom filter
    BloomFilter *bF;

public:
    // constructor
    CheckUrl(BloomFilter *bF);

    // execute the command
    bool execute(string url);
};

#endif