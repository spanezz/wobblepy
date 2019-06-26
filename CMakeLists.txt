cmake_minimum_required(VERSION 3.2)

include(FindDoxygen)
set(VERSION "1.0")
add_definitions(-DPOSIX)
add_subdirectory(wobblepy)
enable_testing()

add_test(wobblepy-test wobblepy/wobblepy-test.py)
