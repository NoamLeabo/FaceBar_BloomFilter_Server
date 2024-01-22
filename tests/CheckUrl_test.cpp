#include <gtest/gtest.h>
#include <sstream>
#include "CheckUrl.h"
#include "BloomFilter.h"
#include "HashNo1.h"
#include "HashNo2.h"
// testing CheckUrl works with URL's
TEST(CheckUrlTest, ExecuteTest) {
    vector<HashFunc*> funcBank;
    HashNo1 f1;
    HashNo2 f2;
    funcBank.push_back(&f1);
    funcBank.push_back(&f2);
    // Create a BloomFilter object
    BloomFilter* bf = new BloomFilter(8,2,funcBank);

    // Create a CheckUrl object
    CheckUrl c1(bf);

    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Call the function that prints to std::cout
    c1.execute("www.example.com0");

    // Restore the original buffer before comparison
    std::cout.rdbuf(prevcoutbuf);

    // Compare the contents of the stringstream with the expected output
    EXPECT_EQ(buffer.str(), "false\n");

    // Delete the BloomFilter object
    delete bf;
}
TEST(CheckUrlTest, ExecuteTest2) {
   vector<HashFunc*> funcBank;
    HashNo1 f1;
    HashNo2 f2;
    funcBank.push_back(&f1);
    funcBank.push_back(&f2);
    // Create a BloomFilter object
    BloomFilter* bf = new BloomFilter(8,1,2,funcBank);
    bf->addUrl("www.example.com0");
    // Create a CheckUrl object
    CheckUrl c1(bf);

    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Call the function that prints to std::cout
    c1.execute("www.example.com0");

    // Restore the original buffer before comparison
    std::cout.rdbuf(prevcoutbuf);

    // Compare the contents of the stringstream with the expected output
    EXPECT_EQ(buffer.str(), "true true\n");

    // Delete the BloomFilter object
    delete bf;
}
