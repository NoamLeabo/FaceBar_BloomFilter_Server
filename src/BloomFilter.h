#ifndef MYCLASS_H
#define MYCLASS_H

#include "HashFunc.h"

#include <string>
#include <map>

using namespace std;

class BloomFilter {
    private:
        int* array;
        int size;
        map<int,int> funcsMap;               
        map<int, HashFunc> hashers;


    public: 
        BloomFilter(int size, int num1);
        BloomFilter(int size, int num1, int num2);
        void addHashFunc(int hashIndex, HashFunc* HashFunc);
        void hashFunc(string url,int amount);
        bool checkFunc(string url,int amount);
        int numHash1();
        int numHash2();
        int arrayLength();
        void addUrl(string url);
        int getIndex();
        bool checkUrl(string url);
};

#endif