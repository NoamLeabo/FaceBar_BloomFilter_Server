#include <iostream>
using namespace std;
class BloomFilter{
    private:
    int* array;
    int size;
    int hash1;


    public:
    // constructor
    BloomFilter(int size,int num1){
        array= new int[size];
        this->size=size;
        hash1=num1;
    }

    // number of times we hash with func 1
     int numHash1(){
        return hash1;
     }

     int arrayLength(){
        return size;
     }
};