cmake_minimum_required(VERSION 3.0)

project(prime)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "-O2 -std=c++11")

include_directories(include)
aux_source_directory(src/ST DIR_SRCS)
aux_source_directory(src/MT DIR_SRCS_MT)
add_link_options()

# enable_testing()

# aux_source_directory(test/test_mt DIR_TEST_MT)
# add_executable(test_mt ${DIR_TEST_MT})
# add_test(test_correction test_mt)

add_executable(prime ${DIR_SRCS})
add_executable(prime_mt ${DIR_SRCS_MT})
if(UNIX)
    target_link_libraries(prime_mt pthread)
endif(UNIX)
