cmake_minimum_required(VERSION 3.20)
project(SDL_InputHandling)

#set(CMAKE_CXX_STANDARD 14)

#When calling find_package, cmake will go to the directory in $SDL2_DIR and
#run sdl2_image-config.cmake
set(SDL2_DIR lib/SDL2)
find_package(SDL2 REQUIRED)
set(SDL2_IMAGE_DIR lib/SDL2_image)
find_package(SDL2_IMAGE REQUIRED)
set(SDL2_TTF_DIR lib/SDL_TTF)
find_package(SDL2_TTF REQUIRED)

add_executable(SDL_InputHandling Demo/src/main.cpp simple_game_engine/src/InputHandler.cpp simple_game_engine/include/GameEvent.h simple_game_engine/include/GameEventType.h
        simple_game_engine/src/GameEvent.cpp simple_game_engine/src/GameObject.cpp simple_game_engine/include/GameObject.h simple_game_engine/src/SimpleObject.cpp simple_game_engine/include/SimpleObject.h
        simple_game_engine/src/ContainerObject.cpp simple_game_engine/include/ContainerObject.h simple_game_engine/include/InputComponent.h Demo/src/GameInputComponent.cpp
        Demo/include/GameInputComponent.h simple_game_engine/src/GraphicsComponent.cpp simple_game_engine/include/GraphicsComponent.h
        Demo/src/snake/SnakeBody.cpp Demo/include/snake/SnakeBody.h Demo/src/snake/SnakeHead.cpp
        Demo/include/snake/SnakeHead.h Demo/src/snake/SnakeInputComponent.cpp Demo/include/snake/SnakeInputComponent.h
        simple_game_engine/src/InputComponent.cpp simple_game_engine/src/PhysicsComponent.cpp simple_game_engine/include/PhysicsComponent.h Demo/src/snake/SnakeWorld.cpp
        Demo/include/snake/SnakeWorld.h Demo/src/snake/SnakeRoot.cpp Demo/include/snake/SnakeRoot.h
        simple_game_engine/common_elements/src/TextObject.cpp simple_game_engine/common_elements/include/TextObject.h simple_game_engine/common_elements/src/CounterTextObject.cpp simple_game_engine/common_elements/include/CounterTextObject.h)
#Libraries to link when compiling this file
target_link_libraries(SDL_InputHandling ${SDL2_LIBRARIES})
target_link_libraries(SDL_InputHandling ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(SDL_InputHandling ${SDL2_TTF_LIBRARIES})
#Include directories to be searched when compiling this file (main.cpp)
target_include_directories(SDL_InputHandling PUBLIC "${SDL2_INCLUDE_DIRS}")
target_include_directories(SDL_InputHandling PUBLIC "${SDL2_IMAGE_INCLUDE_DIRS}")
target_include_directories(SDL_InputHandling PUBLIC "${SDL2_TTF_INCLUDE_DIRS}")

target_include_directories(SDL_InputHandling PUBLIC simple_game_engine/include)
target_include_directories(SDL_InputHandling PUBLIC simple_game_engine/common_elements/include)

