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
BloomFilter::BloomFilter(int size, int num1) : numOfHashers(0), size(size), array(new int[size]), list(new vector<string>)
{
   // we add HF (stands for HashFunc) to the BF (stands for BloomFilter)
   if (num1 == 1)
   {
      HashNo1 *f1 = new HashNo1();
      addHashFunc(1, f1);
   }
   else {
      HashNo2 *f1 = new HashNo2();
      addHashFunc(1, f1);
   }
}

// constructor for 2 hash funcs
BloomFilter::BloomFilter(int sizem, int num1, int num2) : numOfHashers(0), size(size), array(new int[size]), list(new vector<string>)
{
   // we add 2 HF to the BF
   HashNo1 *f1 = new HashNo1();
   addHashFunc(1, f1);
   HashNo2 *f2 = new HashNo2();
   addHashFunc(2, f2);
}

// adding the BF another HF
void BloomFilter::addHashFunc(int index, HashFunc *hashFunc)
{
   // we add to the BF another HF
   this->hashers[index] = hashFunc;
   // updating the current Num of HF we have so far
   this->numOfHashers++;
}

// add URL to BF
void BloomFilter::addUrl(string url)
{
   hashFunc(url);
   this->list->push_back(url);
}

// hashig the string and inserting its value to the BF
void BloomFilter ::hashFunc(string url)
{
   // for each HF we the BF has we get the URL's H-value and updating teh array acordingly
   for (size_t i = 1; i <= this->numOfHashers; i++)
   {
      hashers[i]->hashing(url);
      int index = hashers[i]->getValue() % size;
      array[index] = 1;
   }
}

// checking if a url is in the BF *TABLE* (terms of bits)
bool BloomFilter ::checkFunc(string url)
{
   // we set an indicator that checks whether we have a match
   bool indicator = true;
   // we check for each HF if the its bit is turned on
   for (size_t i = 1; i <= numOfHashers; i++)
   {
      // doing the hashing the url with the HF i
      hashers[i]->hashing(url);
      // mod on the result
      int index = hashers[i]->getValue() % size;
      // looking for a match in the array
      if (array[index] == 1)
         indicator = true;
      else
      {
         indicator = false;
         break;
      }
   }
   return indicator;
}

// checking if a url is actually in the BF blacklist
bool BloomFilter ::blacklistCheck(string url)
{
   // we scan the list of confirmed blacklist and check if the given url is there
   auto scan = find(this->list->begin(), this->list->end(), url);
   if (scan != this->list->end())
   {
      return true;
   }
   else
      return false;
}

// return the BF's size
int BloomFilter::arrayLength()
{
   return size;
}

// get index which is 1 after 1 hash func => we use this for the tests
int BloomFilter::getIndex()
{
   for (int i = 0; i < size; i++)
   {
      if (array[i] == 1)
         return 1;
   }
   return -1;
}