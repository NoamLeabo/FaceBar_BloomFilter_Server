#ifndef MYCLASS_H
#define MYCLASS_H

#include "HashFunc.h"

#include <string>
#include <map>

using namespace std;

class BloomFilter
{
private:
    int *array;
    int size;
    vector<string> *list;
    map<int, HashFunc> hashers;
    int numOfHashers;

public:
    BloomFilter(int size, int num1);
    BloomFilter(int size);
    void addHashFunc(int hashIndex, HashFunc *HashFunc);
    void hashFunc(string url);
    bool checkFunc(string url);
    int arrayLength();
    void addUrl(string url);
    int getIndex();
    bool blacklistCheck(string url);
};

#endif