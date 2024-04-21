#include "CheckUrl.h"
#include "BloomFilter.h"
#include <iostream>

// constuctor
CheckUrl::CheckUrl(BloomFilter *bF) : bF(bF) {}

// we check whether the given URL is in the BF
bool CheckUrl::execute(string url) {
    // first checking if the URL is in the array in terms of bits
    bool check = this->bF->checkInBitsArray(url);

    // if we get positive we must check whether it's false positive
    if (check) {
        cout << "true ";
        // we wish to make sure that the URL is actually in the blacklist
        bool check = this->bF->urlBlacklistCheck(url);
        // we print as the results say
        if (check) {
            cout << "true" << endl;
            return true;
        } else {
            cout << "false" << endl;
            return false;
        }
    }
        // if we get negative we simply print false
    else
        cout << "false" << endl;
    return false;
}