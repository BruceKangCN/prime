cmake_minimum_required(VERSION 3.0)

project(prime)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS "-O2 -std=c++11")

include_directories(include)
aux_source_directory(src/ST DIR_SRCS)
aux_source_directory(src/MT DIR_SRCS_MT)
add_link_options()

add_executable(prime ${DIR_SRCS})
add_executable(prime_mt ${DIR_SRCS_MT})
if(UNIX)
    target_link_libraries(prime_mt pthread)
endif(UNIX)

enable_testing()
add_library(primemt STATIC src/MT/mt.cpp)
aux_source_directory(test/test_mt DIR_TEST_MT)
add_executable(test_mt ${DIR_TEST_MT})
target_link_libraries(test_mt gtest primemt)
if(UNIX)
    target_link_libraries(test_mt pthread)
endif(UNIX)
add_test(test_correction test_mt)
