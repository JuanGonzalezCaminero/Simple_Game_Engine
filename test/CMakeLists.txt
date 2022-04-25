cmake_minimum_required(VERSION 3.20)

project(googletest)

include_directories(googletest/googletest/include googletest/googletest/src)

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run basic_test.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)