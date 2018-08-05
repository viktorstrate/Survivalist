//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <SDL.h>
#include <string>

#include "core/GameObject.h"
#include "math/vector.h"
#include "math/size.h"

namespace survivalist {

    class GameWorld;

    class Entity : public GameObject {
    public:
        Entity(const size &size, const vector &position);

        void setTexture(std::string name, GameWorld* world);

        void update(Uint32 dt) override {}

#ifdef GAME_CLIENT
        void render(Graphics* graphics) override;
#endif

        const size& getSize() const;

        vector gPosition;

    protected:
        size gSize;

    protected:
#ifdef GAME_CLIENT
        SDL_Texture* gTexture = nullptr;
#endif
    };

}
