cmake_minimum_required(VERSION 3.20)
project(demo)

#set(CMAKE_CXX_STANDARD 14)

add_executable(demo
        Demo/src/main.cpp
        Demo/src/GameInputComponent.cpp
        Demo/src/snake/SnakeBody.cpp
        Demo/src/snake/SnakeHead.cpp
        Demo/src/snake/SnakeInputComponent.cpp
        Demo/src/snake/SnakeWorld.cpp
        Demo/src/snake/SnakeRoot.cpp
        Demo/src/snake/ExitButtonInputComponent.cpp
        )

add_subdirectory(simple_game_engine)

#When calling find_package, cmake will go to the directory in $SDL2_DIR and
#run sdl2_image-config.cmake
set(SDL2_DIR ${CMAKE_SOURCE_DIR}/simple_game_engine/lib/SDL2)
find_package(SDL2 REQUIRED)
set(SDL2_IMAGE_DIR ${CMAKE_SOURCE_DIR}/simple_game_engine/lib/SDL2_image)
find_package(SDL2_IMAGE REQUIRED)
set(SDL2_TTF_DIR ${CMAKE_SOURCE_DIR}/simple_game_engine/lib/SDL_TTF)
find_package(SDL2_TTF REQUIRED)

#Libraries to link when compiling this file
target_link_libraries(demo ${SDL2_LIBRARIES})
target_link_libraries(demo ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(demo ${SDL2_TTF_LIBRARIES})

target_link_libraries(demo sge_base)
target_link_libraries(demo sge_extra)

#Include directories to be searched when compiling this file (main.cpp)
target_include_directories(demo PUBLIC "${SDL2_INCLUDE_DIRS}")
target_include_directories(demo PUBLIC "${SDL2_IMAGE_INCLUDE_DIRS}")
target_include_directories(demo PUBLIC "${SDL2_TTF_INCLUDE_DIRS}")

target_include_directories(demo PUBLIC simple_game_engine/base/include)
target_include_directories(demo PUBLIC simple_game_engine/extra/include)
target_include_directories(demo PUBLIC demo/include/snake)
target_include_directories(demo PUBLIC demo/include)


