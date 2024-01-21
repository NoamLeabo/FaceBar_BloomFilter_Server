#include "AddUrl.h"
#include "BloomFilter.h"


AddUrl::AddUrl(BloomFilter* bF) : bF(bF) {}


void AddUrl::execute(string url){
    this->bF->addUrl(url);
}