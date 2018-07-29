//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

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
#endif

    protected:
        void gameLoop();

    };

}
