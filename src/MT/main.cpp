#include <cstdio>

#include "main_mt.h"

#define MAX (1 << 30)
#define OUTPUT (false)

int main()
{
    std::list<uint64_t> list = std::move(prime::generatePrime(MAX));

    if (OUTPUT) {
        for (auto&& i : list) {
            std::printf("%ld\n", i);
        }
    }
    std::printf("length: %ld\n", list.size());

    return 0;
}
