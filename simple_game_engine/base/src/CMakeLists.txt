cmake_minimum_required(VERSION 3.20)
project(sge_base)

add_library(sge_base OBJECT
            ContainerObject.cpp
            GameEvent.cpp
            GameObject.cpp
            GraphicsComponent.cpp
            InputComponent.cpp
            InputHandler.cpp
            PhysicsComponent.cpp
            SimpleObject.cpp)

target_include_directories(sge_base PUBLIC "${SGE_BASE_INCLUDE_DIR}")
target_include_directories(sge_base PUBLIC "${SDL2_INCLUDE_DIRS}")
target_include_directories(sge_base PUBLIC "${SDL2_IMAGE_INCLUDE_DIRS}")
target_include_directories(sge_base PUBLIC "${SDL2_TTF_INCLUDE_DIRS}")