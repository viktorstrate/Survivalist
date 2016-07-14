cmake_minimum_required(VERSION 3.4)
project(Survivalist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

LIST(APPEND CMAKE_MODULE_PATH cmake_modules)

# Find libraries
find_package(SDL2 REQUIRED)


add_subdirectory(src)