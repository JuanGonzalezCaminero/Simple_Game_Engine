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

add_executable(SDL_InputHandling Demo/src/main.cpp src/InputHandler.cpp include/GameEvent.h include/GameEventType.h
        src/GameEvent.cpp src/GameObject.cpp include/GameObject.h src/SimpleObject.cpp include/SimpleObject.h
        src/ContainerObject.cpp include/ContainerObject.h include/InputComponent.h Demo/src/GameInputComponent.cpp
        Demo/include/GameInputComponent.h src/GraphicsComponent.cpp include/GraphicsComponent.h
        Demo/src/snake/SnakeBody.cpp Demo/include/snake/SnakeBody.h Demo/src/snake/SnakeHead.cpp
        Demo/include/snake/SnakeHead.h Demo/src/snake/SnakeInputComponent.cpp Demo/include/snake/SnakeInputComponent.h
        src/InputComponent.cpp src/PhysicsComponent.cpp include/PhysicsComponent.h Demo/src/snake/SnakeWorld.cpp
        Demo/include/snake/SnakeWorld.h Demo/src/snake/SnakeRoot.cpp Demo/include/snake/SnakeRoot.h
        Demo/src/snake/TextObject.cpp Demo/include/snake/TextObject.h Demo/src/snake/CounterTextObject.cpp Demo/include/snake/CounterTextObject.h)
#Libraries to link when compiling this file
target_link_libraries(SDL_InputHandling ${SDL2_LIBRARIES})
target_link_libraries(SDL_InputHandling ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(SDL_InputHandling ${SDL2_TTF_LIBRARIES})
#Include directories to be searched when compiling this file (main.cpp)
target_include_directories(SDL_InputHandling PUBLIC "${SDL2_INCLUDE_DIRS}")
target_include_directories(SDL_InputHandling PUBLIC "${SDL2_IMAGE_INCLUDE_DIRS}")
target_include_directories(SDL_InputHandling PUBLIC "${SDL2_TTF_INCLUDE_DIRS}")


