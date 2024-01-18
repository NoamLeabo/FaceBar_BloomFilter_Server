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
TEST(MainTest,BFTest){
    FilterRunner runner;
    // Capture the standard output
    testing::internal::CaptureStdout();
    // Call the function that prints to the screen
    runner.run("8 1");
    // Get the captured output
    std::string output = testing::internal::GetCapturedStdout();
    // Assert on the output
    EXPECT_EQ(output,"true");
}