//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <vector>

#include "client/Client.h"
#include "core/World.h"
#include "game/Player.h"

namespace survivalist {

    class GameWorld : public World {
    public:

#ifdef GAME_SERVER
        explicit GameWorld();
#endif

        void init();

        void update(Uint32 dt) override;

#ifdef GAME_CLIENT

        explicit GameWorld(Graphics* graphics);

        void render(Graphics* graphics) override;

        void handleEvent(SDL_Event* event) override;

#endif

    private:
        std::vector<Player> players;

    };

}
