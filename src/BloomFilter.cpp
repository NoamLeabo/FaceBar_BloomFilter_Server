#include <iostream>
using namespace std;
class BloomFilter{
    private:
    int* array;
    int size;
    int hash1;
    int hash2;


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
};