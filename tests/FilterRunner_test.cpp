#include <gtest/gtest.h>
#include "../src/FilterRunner.cpp"

// testing that main runs 
TEST(MainTest,Test1){
    FilterRunner runner;
    EXPECT_NO_FATAL_FAILURE();
}
// testing that BF is made
TEST(MainTest,Test2){
    FilterRunner runner(8,1);
    EXPECT_NO_FATAL_FAILURE();
}