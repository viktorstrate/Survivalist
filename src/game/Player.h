//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include "core/Entity.h"

namespace survivalist {

    class GameWorld;

    class Player : public Entity {
    public:
        Player(GameWorld* world, const vector &position, bool locallyControlled);

        void update(Uint32 dt) override;

#ifdef GAME_CLIENT
        void handleEvent(SDL_Event* event) override;
#endif

    protected:

        double gSpeed = 100;

        bool gLocallyControlled;

    private:

        GameWorld* gWorld;

    };

}

