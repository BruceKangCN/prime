#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <cstdio>
#include <list>
#include <mutex>
#include <thread>

#define MAX (1 << 30)
#define END (MAX & 0xfffffffffffffffe - 1)
#define OUTPUT (false)

unsigned running_count = 0;
std::mutex value_mutex;
std::mutex list_mutex;
std::mutex m;

std::list<uint64_t>::iterator search_r(std::list<uint64_t>& list, uint64_t v)
{
    if (v > list.back()) {
        return list.end();
    }
    auto place = list.end();
    uint64_t prime;
    while ((prime = *(--place)) > v) { }
    return ++place;
}

void isPrime(uint64_t& value, std::list<uint64_t>& list)
{
    auto start = std::chrono::system_clock::now().time_since_epoch();

    uint64_t v;
    while (true) {
        {
            std::lock_guard<std::mutex> guard(value_mutex);
            v = value;
            value += 2;
        }
        if (v > END) {
            break;
        }
        bool flag = true;
        for (auto&& prime : list) {
            if (prime * prime > v) {
                break;
            }
            if (v % prime == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::lock_guard<std::mutex> guard(list_mutex);
            list.insert(search_r(list, v), v);
        }
    }

    auto end = std::chrono::system_clock::now().time_since_epoch();
    std::printf("thread finish in %ld ms.\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    {
        std::lock_guard<std::mutex> guard(m);
        running_count--;
    }
}

int main()
{
    std::list<uint64_t> list = { 2 };
    uint64_t value = 3;

    for (unsigned i = 0; i < std::thread::hardware_concurrency(); i++) {
        std::thread(isPrime, std::ref(value), std::ref(list)).detach();
        running_count++;
    }

    while (running_count > 0) {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
    if (OUTPUT) {
        for (auto&& i : list) {
            std::printf("%ld\n", i);
        }
    }
    std::printf("length: %ld\n", list.size());

    return 0;
}
