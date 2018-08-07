//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#pragma once

#include <chrono>
#include <enet/enet.h>

#include "client/Graphics.h"
#include "InputHandler.h"
#include "game/GameWorld.h"

namespace survivalist {

    class Client {

    public:
        Client();
        ~Client();

        bool connectToServer(const char* host, unsigned short port);

        void changeWorld(World* newWorld);

        bool willQuit;
        World* gWorld;

        Graphics gGraphics;
        Uint32 gPreviousUpdateTime = 0;

        ENetAddress gAddress;
        ENetPeer* gPeer;
        ENetHost* gClient;

    protected:
        void gameLoop();

    };

}
