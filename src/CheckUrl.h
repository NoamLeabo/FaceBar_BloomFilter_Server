#ifndef CHECKURL_H
#define CHECKURL_H
#include <string>
#include <map>
#include "ICommandable.h"
#include "BloomFilter.h"


using namespace std;

class CheckUrl : public ICommandable
{
private:
    BloomFilter* bF;

public:
    CheckUrl(BloomFilter* bF);
    void execute(string url);
};

#endif