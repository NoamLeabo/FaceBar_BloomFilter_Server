#include <iostream>
#include "BloomFilter.h"
#include "HashNo1.h"
#include "HashNo2.h"
#include "HashFunc.h"
#include <vector>
#include <algorithm>

using namespace std;

#include <string>
#include <map>

// constructor
BloomFilter::BloomFilter(int size, int num1, vector<HashFunc *> funcBank)
        : funcBank(funcBank), numOfHashers(0), size(size), array(),
          list() {
    // we inject the required hashFunc from the funcBank
    addHashFunc(1, this->funcBank.at(num1 - 1));
    // we reset the array size
    resetBitsArray(size);
}

// constructor for 2 hash funcs
BloomFilter::BloomFilter(int size, int num1, int num2,
                         vector<HashFunc *> funcBank) : funcBank(funcBank),
                                                        numOfHashers(0),
                                                        size(size),
                                                        array(), list() {
    // we inject the required hashFuncs from the funcBank
    addHashFunc(1, this->funcBank.at(num1 - 1));
    addHashFunc(2, this->funcBank.at(num2 - 1));
    // we reset the array size
    resetBitsArray(size);
}

void BloomFilter::resetBitsArray(int size) {
    for (int i = 0; i < size; ++i) {
        array.push_back(0);
    }
}

// adding the BF another HF
void BloomFilter::addHashFunc(int index, HashFunc *hashFunc) {
    // we add to the BF another HF
    this->hashers[index] = hashFunc;
    // updating the current Num of HF we have so far
    this->numOfHashers++;
}

// add URL to BF
void BloomFilter::addUrl(string url) {
    hashFunc(url);
    this->list.push_back(url);
}

// hashig the string and inserting its value to the BF
void BloomFilter::hashFunc(string url) {
    // for each HF the BF has we get the URL's H-value and updating teh array acordingly
    for (size_t i = 1; i <= this->numOfHashers; i++) {
        hashers[i]->hashing(url);
        int index = hashers[i]->getValue() % size;
        array[index] = 1;
    }
}

// checking if an url is in the BF *TABLE* (terms of bits)
bool BloomFilter::checkInBitsArray(string url) {
    // we set an indicator that checks whether we have a match
    bool indicator = true;
    // we check for each HF if its bit is turned on
    for (size_t i = 1; i <= numOfHashers; i++) {
        // doing the hashing the url with the HF i
        hashers[i]->hashing(url);
        // mod on the result
        int index = hashers[i]->getValue() % size;
        // looking for a match in the array
        if (array[index] == 1)
            indicator = true;
        else {
            indicator = false;
            break;
        }
    }
    return indicator;
}

// checking if an url is actually in the BF blacklist
bool BloomFilter::urlBlacklistCheck(string url) {

    /* we scan the list of confirmed blacklist and check if the given url
    is there*/

    auto scan = find(this->list.begin(), this->list.end(), url);
    if (scan != this->list.end()) {
        return true;
    } else
        return false;
}

// return the BF's size
int BloomFilter::arrayLength() {
    return size;
}

// get index which is 1 after 1 hash func => we use this for the tests
int BloomFilter::getIndex() {
    for (int i = 0; i < size; i++) {
        if (array[i] == 1)
            return 1;
    }
    return -1;
}