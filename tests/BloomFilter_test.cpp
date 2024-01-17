#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp"

// testing basic built with 1 hash func
TEST(BuildTest,BasicTest1) {
    BloomFilter f1(8,1);
    EXPECT_EQ(f1.arrayLength(),8);
    EXPECT_EQ(f1.numHash1(),1);
    
}
// testing basic built with 2 hash func
TEST(BuildTest,BasicTest2) {
    BloomFilter f1(8,1,2);
    EXPECT_EQ(f1.arrayLength(),8);
    EXPECT_EQ(f1.numHash1(),1);
    EXPECT_EQ(f1.numHash2(),2);
}
// testing adding and searching url in BF
TEST(AddTest,BasicTest3){
    BloomFilter f1(8,1);
    EXPECT_NO_THROW(f1.addUrl("www.example.com0"));
    EXPECT_EQ(f1.checkUrl("www.example.com0"),true);
}
