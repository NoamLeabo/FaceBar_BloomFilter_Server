#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include "HashFunc.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class BloomFilter {
private:
    vector<int> array;
    int size;
    vector<string> list;
    vector<HashFunc *> funcBank;
    map<int, HashFunc *> hashers;
    int numOfHashers;

    void resetBitsArray(int size);

public:
    BloomFilter(int size, int num1, vector<HashFunc *> funcBank);

    BloomFilter(int size, int num1, int num2, vector<HashFunc *> funcBank);

    void addHashFunc(int hashIndex, HashFunc *HashFunc);

    void hashFunc(string url);

    bool checkInBitsArray(string url);

    int arrayLength();

    void addUrl(string url);

    int getIndex();

    bool urlBlacklistCheck(string url);
};

#endif