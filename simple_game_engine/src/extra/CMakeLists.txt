cmake_minimum_required(VERSION 3.20)
project(sge_extra)

add_library(sge_extra OBJECT
            CounterTextObject.cpp
            TextObject.cpp)

target_include_directories(sge_extra PUBLIC "${SGE_BASE_INCLUDE_DIR}")
target_include_directories(sge_extra PUBLIC "${SGE_EXTRA_INCLUDE_DIR}")
target_include_directories(sge_extra PUBLIC "${SDL2_INCLUDE_DIRS}")
target_include_directories(sge_extra PUBLIC "${SDL2_IMAGE_INCLUDE_DIRS}")
target_include_directories(sge_extra PUBLIC "${SDL2_TTF_INCLUDE_DIRS}")