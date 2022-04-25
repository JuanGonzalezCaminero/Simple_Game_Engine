cmake_minimum_required(VERSION 3.20)
project(simple_game_engine)

set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2)
find_package(SDL2 REQUIRED)
set(SDL2_IMAGE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2_image)
find_package(SDL2_IMAGE REQUIRED)
set(SDL2_TTF_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL_TTF)
find_package(SDL2_TTF REQUIRED)

set(SGE_BASE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/base/include)
set(SGE_EXTRA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extra/include)

add_subdirectory(base/src/)
add_subdirectory(extra/src)