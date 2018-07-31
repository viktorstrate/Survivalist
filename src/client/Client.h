//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <chrono>
#include <enet/enet.h>

#include "client/Graphics.h"
#include "core/World.h"

namespace survivalist {

    class Client {

    public:
        Client();
        ~Client();

        bool willQuit;
        World* gWorld;

        Graphics gGraphics;
        Uint32 gPreviousUpdateTime;

        ENetAddress gAddress;
        ENetPeer* gPeer;
        ENetHost* gClient;

    protected:
        void gameLoop();

    };

}
