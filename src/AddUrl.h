#ifndef ADDURL_H
#define ADDURL_H

#include <string>
#include <map>
#include "ICommandable.h"
#include "BloomFilter.h"

using namespace std;

// AddUrl class
class AddUrl : public ICommandable {
private:
    // bloom filter
    BloomFilter *bF;

public:
    // constructor
    AddUrl(BloomFilter *bF);

    // execute the command
    bool execute(string url);
};

#endif