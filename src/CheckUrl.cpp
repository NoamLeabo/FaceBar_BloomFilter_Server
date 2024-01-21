#include "CheckUrl.h"
#include "BloomFilter.h"
#include <iostream>

CheckUrl::CheckUrl(BloomFilter* bF) : bF(bF) {}

void CheckUrl::execute(string url)
{
    bool check = this->bF->checkFunc(url);
    // if true need to check if false positive
    if (check)
    {
        cout << "true ";
        bool check = this->bF->blacklistCheck(url);
        if (check)
        {
            cout << "true" << endl;
        }
        else
            cout << "false" << endl;
    }
    else
        cout << "false" << endl;
}