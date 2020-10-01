#ifndef MAIN_MT_H
#define MAIN_MT_H

#include <chrono>
#include <cstdint>
#include <list>
#include <mutex>
#include <thread>

namespace prime {
std::list<uint64_t> generatePrime(uint64_t max);
}

#endif // MAIN_MT_H