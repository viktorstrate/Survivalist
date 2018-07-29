cmake_minimum_required(VERSION 3.4)


set(SOURCES
        client.cpp
        Game.cpp Game.h Entity.cpp Entity.h TextureHandler.cpp TextureHandler.h)

add_executable(${PROJECT_NAME}_Client ${SOURCES})

target_link_libraries(${PROJECT_NAME}_Client ${SDL2_LIBRARY})
target_link_libraries(${PROJECT_NAME}_Client ${SDL2_IMAGE_LIBRARY})