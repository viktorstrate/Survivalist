//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <chrono>

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

    protected:
        void gameLoop();

    };

}
