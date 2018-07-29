//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <SDL.h>
#include <string>

#include "core/Game.h"
#include "math/vector.h"
#include "math/size.h"

namespace survivalist {

    class Entity {
    public:
        Entity(const size &size, const vector &position);

        void setTexture(std::string name, Game* game);

        virtual void update(float dt) {}

#ifdef GAME_CLIENT
        void render(SDL_Renderer* renderer);
#endif

    protected:
        vector gPosition;
        size gSize;

#ifdef GAME_CLIENT
        SDL_Texture* gTexture = nullptr;
#endif
    };

}
