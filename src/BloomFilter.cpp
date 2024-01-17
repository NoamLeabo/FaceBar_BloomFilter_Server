#include <iostream>
using namespace std;
#include <string>
class BloomFilter{
    private:
    int* array;
    int size;
    int hash1;
    int hash2;

    // hash with func1 or func2. "amount" times we hash with func
    void hashFunc(string url,int amount){
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
    bool checkFunc(string url,int amount){
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
    
    public:
    // constructor
    BloomFilter(int size,int num1){
        array= new int[size];
        this->size=size;
        hash1=num1;
        hash2=0;
    }
    // constructor for 2 hash funcs
    BloomFilter(int size,int num1,int num2){
        array= new int[size];
        this->size=size;
        hash1=num1;
        hash2=num2;
    }

     // number of times we hash with func 1
     int numHash1(){
        return hash1;
     }

     // number of times we hash with func 2
     int numHash2(){
        return hash2;
     }

     int arrayLength(){
        return size;
     }
     // add URL to BF
     void addUrl(string url){
      hashFunc(url,hash1);
      hashFunc(url,hash2);
     }
     // get index which is 1 after 1 hash func => we use this for the tests
     int getIndex(){
      for ( int i = 0; i < size; i++)
      {
         if(array[i]==1)
            return 1;
      }
      return -1;
     }

     // check if URL is in BF
     bool checkUrl(string url){
      return checkFunc(url,hash1) && checkFunc(url,hash2);
     }

};