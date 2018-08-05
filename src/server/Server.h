//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <chrono>
#include <enet/enet.h>

#include "game/GameWorld.h"
#include "client/Graphics.h"

namespace survivalist {

    class Server {

    public:
        Server();
        ~Server();

        bool willQuit;
        GameWorld* gWorld;

        std::chrono::time_point<std::chrono::high_resolution_clock> gPreviousUpdateTime;

        ENetAddress gAddress;
        ENetHost* gHost;

    protected:
        void gameLoop();

    };

}
