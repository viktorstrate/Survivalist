//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <SDL.h>
#include "GameObject.h"

namespace survivalist {

    class Graphics;

    class World : public GameObject {
    public:

        virtual ~World() = default;

#ifdef GAME_CLIENT

        World(Graphics* gGraphics) : gGraphics(gGraphics) {}

        Graphics* gGraphics;
#endif

    };

}
