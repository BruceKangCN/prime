#include <chrono>
#include <cstdint>
#include <cstdio>
#include <list>

#define MAX (1 << 30)

int main()
{
    auto start = std::chrono::system_clock::now().time_since_epoch();

    std::list<uint64_t> list = { 2 };
    for (uint64_t i = 3; i < MAX; i += 2) {
        bool flag = true;
        for (auto&& prime : list) {
            if (prime * prime > i) {
                break;
            }
            if (i % prime == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            list.push_back(i);
        }
    }

    auto end = std::chrono::system_clock::now().time_since_epoch();

    // std::printf("elapsed: %ld\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    // for (auto&& v : list) {
    //     std::printf("%ld\n", v);
    // }
    std::printf("length: %ld\n", list.size());
    std::printf("elapsed: %ld\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    return 0;
}