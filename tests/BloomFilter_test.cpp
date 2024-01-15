#include <gtest/gtest.h>
#include "../src/BloomFilter"


TEST(BuildTest,BasicTest) {
    BloomFilter f1(8,1);
    EXPECT_EQ(f1.arrayLength(),1);
    EXPECT_EQ(f1.numHash1(),1);
    
}
