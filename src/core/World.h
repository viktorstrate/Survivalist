//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <SDL.h>

namespace survivalist {

    class World {
    public:

        virtual ~World() = default;

        virtual void update(float dt) = 0;

#ifdef GAME_CLIENT
        virtual void render(SDL_Renderer* renderer) = 0;

        virtual void handleEvent(SDL_Event* event) = 0;
#endif

    };

}
