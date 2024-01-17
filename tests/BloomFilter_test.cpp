#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp"


TEST(BuildTest,BasicTest) {
    BloomFilter f1(8,1);
    EXPECT_EQ(f1.arrayLength(),8);
    EXPECT_EQ(f1.numHash1(),1);
    
}

TEST(BuildTest,BasicTest2) {
    BloomFilter f1(8,1,2);
    EXPECT_EQ(f1.arrayLength(),8);
    EXPECT_EQ(f1.numHash1(),1);
    EXPECT_EQ(f1.numHash2(),2);
    
}
