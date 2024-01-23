#include <gtest/gtest.h>
#include "HashNo1.h"
#include "HashNo2.h"
#include "HashFunc.h"
// testing HashNo2 runs
TEST(BaxicTest,TestNoFailure){
    HashNo2 f2;
    EXPECT_NO_FATAL_FAILURE(f2.hashing("www.example.com0"));
    EXPECT_NO_FATAL_FAILURE(f2.getValue());
}