//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <chrono>

#include "client/Graphics.h"
#include "core/World.h"

namespace survivalist {

    class Game {

    public:
        Game();
        ~Game();

        bool willQuit;
        World* gWorld;

#ifdef GAME_CLIENT
        Graphics gGraphics;
        Uint32 gPreviousUpdateTime;
#endif

#ifdef GAME_SERVER
        std::chrono::time_point<std::chrono::high_resolution_clock> gPreviousUpdateTime;
#endif

    protected:
        void gameLoop();

    };

}
