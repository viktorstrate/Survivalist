cmake_minimum_required(VERSION 3.4)


set(SHARED_SOURCES
        main.cpp

        core/Entity.cpp core/Entity.h
        core/Game.cpp core/Game.h
        core/World.h

        math/vector.h math/vector.cpp
        math/size.h

        game/GameWorld.cpp game/GameWorld.h
        game/Player.cpp game/Player.h )

set(CLIENT_SOURCES
        client/Graphics.cpp client/Graphics.h
        client/TextureHandler.cpp client/TextureHandler.h
        )

set(SERVER_SOURCES)

# Client Target

set(CLIENT_TARGET ${PROJECT_NAME}Client)

add_executable(${CLIENT_TARGET} ${SHARED_SOURCES} ${CLIENT_SOURCES})

target_compile_definitions(${CLIENT_TARGET} PRIVATE GAME_CLIENT=1)

target_link_libraries(${CLIENT_TARGET} ${SDL2_LIBRARY})
target_link_libraries(${CLIENT_TARGET} ${SDL2_IMAGE_LIBRARY})

# Server Target

set(SERVER_TARGET ${PROJECT_NAME}Server)

add_executable(${SERVER_TARGET} ${SHARED_SOURCES} ${SERVER_SOURCES})

target_compile_definitions(${SERVER_TARGET} PRIVATE GAME_SERVER=1)