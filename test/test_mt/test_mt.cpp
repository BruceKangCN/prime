#include <gtest/gtest.h>

#include "main_mt.h"

TEST(MT, correction)
{
    std::list<uint64_t> l = {
        2,
        3,
        5,
        7,
        11,
        13,
        17,
        19,
        23,
        29,
        31,
        37,
        41,
        43,
        47,
        53,
        59,
        61,
        67,
        71,
        73,
        79,
        83,
        89,
        97
    };
    std::list<uint64_t> gen = prime::generatePrime(100);
    EXPECT_EQ(l, gen);
    EXPECT_TRUE(true);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}