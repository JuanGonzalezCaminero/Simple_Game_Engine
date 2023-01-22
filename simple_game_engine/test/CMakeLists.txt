cmake_minimum_required(VERSION 3.20)

project(googletest)

add_subdirectory(googletest)
include_directories(googletest/googletest/include googletest/googletest/src)
include_directories(../include/base ../include/extra)
include_directories(../lib/SDL2/include ../lib/SDL2_image/include ../lib/SDL_TTF/include)

set(SDL2_DIR ../lib/SDL2)
find_package(SDL2 REQUIRED)
set(SDL2_IMAGE_DIR ../lib/SDL2_image)
find_package(SDL2_IMAGE REQUIRED)
set(SDL2_TTF_DIR ../lib/SDL_TTF)
find_package(SDL2_TTF REQUIRED)

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run basic_test.cpp TestGameObject.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)