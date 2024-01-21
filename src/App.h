#ifndef APP_H
#define APP_H
#include <string>
#include <map>
#include "BloomFilter.h"
class App{
private:
    BloomFilter bloomFilter;

public:
    App();
    void run();

};

#endif