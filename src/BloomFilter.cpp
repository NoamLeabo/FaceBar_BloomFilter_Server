#include <iostream>
#include "BloomFilter.h"
#include "HashFunc.h"

using namespace std;
#include <string>
#include <map>

 // constructor
   BloomFilter::BloomFilter(int size,int num1){
        array= new int[size];
        this->size=size;
        funcsMap[1]=num1;
   }
    // constructor for 2 hash funcs
   BloomFilter::BloomFilter(int size,int num1,int num2){
        array= new int[size];
        this->size=size;
        funcsMap[1]=num1;
        funcsMap[2]=num2;
   }

   void BloomFilter :: hashFunc(string url,int amount){
      size_t hashed=std::hash<string>()(url);

      for (int i = 1; i <= amount-1; i++)
      {
         // hashing the hashed string again 
         hashed=std::hash<string>()(to_string(hashed));
      }
      int index=hashed%size;
      array[index]=1;
   }
    
    // to complete finding in BF we need to hash the URL according to the amounts and see if we get 1 in the index 
    bool BloomFilter :: checkFunc(string url,int amount) {
      // maybe for examp: func2=0 so we dont need to hash
      if(amount==0)
         return true;
      size_t hashed=std::hash<string>()(url);
      for (int i = 1; i <= amount-1; i++)
      {
         // hashing the hashed string again 
         hashed=std::hash<string>()(to_string(hashed));
      }
      int index=hashed%size;
      if(array[index]==1)
         return true;
      return false;
   }

   void BloomFilter:: addHashFunc(int index, HashFunc* hashFunc){
      this->hashers[index] = *hashFunc;
   }

     // number of times we hash with func 1
   int BloomFilter:: numHash1(){
        return funcsMap[1];
   }

     // number of times we hash with func 2
   int BloomFilter:: numHash2(){
        return funcsMap[2];
   }

   int BloomFilter:: arrayLength(){
        return size;
   }
     // add URL to BF
   void BloomFilter:: addUrl(string url){
      for (auto &entry : funcsMap)
      {
         hashFunc(url,entry.second);
      }
   }
     // get index which is 1 after 1 hash func => we use this for the tests
   int BloomFilter:: getIndex(){
      for ( int i = 0; i < size; i++)
      {
         if(array[i]==1)
            return 1;
      }
      return -1;
   }

     // check if URL is in BF
   bool BloomFilter:: checkUrl(string url){
      for (auto &entry : funcsMap)
      {
         bool result=checkFunc(url,entry.second);
         if (result==false)
            return false;
      }
      return true;
   }