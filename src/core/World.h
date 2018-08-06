//
// Created by Viktor Hundahl Strate on 07/08/2018.
//

#pragma once

#include "client/Graphics.h"

namespace survivalist {

    class World {
    public:
        virtual void update(unsigned int dt) = 0;

        virtual ~World() {};

#ifdef GAME_SERVER
        explicit World() {}
#endif

#ifdef GAME_CLIENT

        explicit World(Graphics* graphics) : gGraphics(graphics) {}

        virtual void render(Graphics* graphics) = 0;

        virtual void handleEvent(SDL_Event* event) = 0;

        Graphics* gGraphics;
#endif

    };

}