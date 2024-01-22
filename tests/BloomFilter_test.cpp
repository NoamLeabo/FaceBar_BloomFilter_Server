#include <gtest/gtest.h>
#include "BloomFilter.h"
#include "HashNo1.h"
#include "HashNo2.h"
#include "HashFunc.h"


// testing adding and searching url in BF
TEST(AddUrlTest, BasicTest3)
{
    BloomFilter f1(8, 1);
    EXPECT_NO_THROW(f1.addUrl("www.example.com0"));
    EXPECT_EQ(f1.checkInBitsArray("www.example.com0"), true);
}

// testing adding and searching url in BF - 2 times hash
// according to example in the exercise
TEST(HashTest, BasicTest4)
{
    BloomFilter f1(8, 2);
    EXPECT_NO_FATAL_FAILURE(f1.addUrl("www.example.com0"));
    EXPECT_EQ(f1.checkInBitsArray("www.example.com4"), true);
}

// testing negative. nothing in BF => need to get False
TEST(NegTest, BasicTest5)
{
    BloomFilter f1(8, 2);
    EXPECT_EQ(f1.checkInBitsArray("www.example.com0"), false);
}

// andvanced test from targil examp1
TEST(Multitest, AdvancedTest1)
{
    BloomFilter f1(8,1,2);
    EXPECT_EQ(f1.checkInBitsArray("www.example.com0"), false);
    EXPECT_NO_THROW(f1.addUrl("www.example.com0"));
    EXPECT_EQ(f1.checkInBitsArray("www.example.com0"), true);
    EXPECT_EQ(f1.urlBlacklistCheck("www.example.com0"), true);
    EXPECT_EQ(f1.checkInBitsArray("www.example.com1"), false);
    EXPECT_EQ(f1.checkInBitsArray("www.example.com11"), true);
    EXPECT_EQ(f1.urlBlacklistCheck("www.example.com11"), false);
}

// andvanced test from targil examp2
TEST(Multitest, AdvancedTest2)
{
    BloomFilter f1(8, 1);
    EXPECT_NO_THROW(f1.addUrl("www.example.com0"));
    EXPECT_EQ(f1.checkInBitsArray("www.example.com0"), true);
    EXPECT_EQ(f1.urlBlacklistCheck("www.example.com0"), true);
    EXPECT_EQ(f1.checkInBitsArray("www.example.com1"), true);
    EXPECT_EQ(f1.urlBlacklistCheck("www.example.com1"), false);
}

// andvanced test from targil examp3
TEST(Multitest, AdvancedTest3)
{
    BloomFilter f1(8, 2);
    EXPECT_NO_THROW(f1.addUrl("www.example.com0"));
    EXPECT_EQ(f1.checkInBitsArray("www.example.com0"), true);
    EXPECT_EQ(f1.urlBlacklistCheck("www.example.com0"), true);
    EXPECT_EQ(f1.checkInBitsArray("www.example.com4"), true);
    EXPECT_EQ(f1.urlBlacklistCheck("www.example.com4"), false);
}