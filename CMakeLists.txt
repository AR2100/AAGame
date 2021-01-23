cmake_minimum_required(VERSION 3.1)

project(AAGame)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "/lib/cmake/SFML")

#include_directories(${PROJECT_SOURCE_DIR}/images)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)
add_executable(AAGame ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(AAGame sfml-graphics sfml-audio)
