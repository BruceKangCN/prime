#include <cassert>

#include "main_mt.h"

int main()
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
    std::list<uint64_t> gen = generatePrime(100);
    assert(l == gen);

    return 0;
}