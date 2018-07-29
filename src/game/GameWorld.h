//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <vector>

#include "core/Game.h"
#include "core/World.h"
#include "game/Player.h"

namespace survivalist {

    class GameWorld : public World {
    public:
        explicit GameWorld(Game* gGame);

        void update(float dt) override;

#ifdef GAME_CLIENT
        void render(SDL_Renderer* renderer) override;

        void handleEvent(SDL_Event* event) override;
#endif

        Game* gGame;

    private:
        Player player;

    };

}
