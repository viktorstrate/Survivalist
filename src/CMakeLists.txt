cmake_minimum_required(VERSION 3.4)

set(EXECUTABLE_NAME Survivalist)

set(SOURCES
        main.cpp
        Game.cpp Game.h)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_link_libraries(Survivalist ${SDL2_LIBRARY})