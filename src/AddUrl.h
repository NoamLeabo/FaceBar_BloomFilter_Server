#ifndef ADDURL_H
#define ADDURL_H
#include <string>
#include <map>
#include "ICommandable.h"
#include "BloomFilter.h"


using namespace std;

class AddUrl : public ICommandable
{
private:
    BloomFilter* bF;

public:
    AddUrl(BloomFilter* bF);
    void execute(string url);
};

#endif