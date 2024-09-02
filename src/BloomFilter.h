#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include "HashFunc.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

// Bloom filter class
class BloomFilter {
private:
    // BF bits array
    vector<int> array;
    // BF size
    int size;
    // list of URLs
    vector<string> list;
    // list of hash functions
    vector<HashFunc *> funcBank;
    // BF hash functions
    map<int, HashFunc *> hashers;
    // number of hash functions
    int numOfHashers;
    // reset the bits array
    void resetBitsArray(int size);
    // set the BF to uninitialized
    bool initialiezed = false;

public:
    // constructor
    BloomFilter(int size, int num1, vector<HashFunc *> funcBank);
    // constructor for 2 hash functions
    BloomFilter(int size, int num1, int num2, vector<HashFunc *> funcBank);
    // add a hash function
    void addHashFunc(int hashIndex, HashFunc *HashFunc);
    // perform hashing on a URL
    void hashFunc(string url);
    // check if a URL has a match within the bits array
    bool checkInBitsArray(string url);
    // get the array length
    int arrayLength();
    // add a URL to the list
    void addUrl(string url);
    // used for testing
    int getIndex();
    // check if a URL is in the blacklist
    bool urlBlacklistCheck(string url);
    // set the BF to initialized
    void setBFInit();
    // get whether the BF is initialized
    bool getBFInit();
    // print the blacklist
    void printBlacklist();
};

#endif