#include <gtest/gtest.h>
#include "../src/FilterRunner.cpp"

// testing that main runs 
TEST(MainTest,Test1){
    FilterRunner runner;
    EXPECT_NO_FATAL_FAILURE();
}
// testing that run is running
TEST(MainTest,Test2){
    FilterRunner runner;
    EXPECT_EQ(runner.run(),0);
}