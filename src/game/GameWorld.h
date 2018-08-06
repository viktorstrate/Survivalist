//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <vector>
#include <SDL.h>
#include "core/World.h"

namespace survivalist {

    class Player;

#ifdef GAME_CLIENT
    class Graphics;
#endif

    class GameWorld : public World {
    public:

        ~GameWorld();

#ifdef GAME_SERVER
        explicit GameWorld();
#endif

        void init();

        void update(unsigned int dt) override;

        void spawnPlayer(Player* player);

#ifdef GAME_CLIENT

        explicit GameWorld(Graphics* graphics);

        void render(Graphics* graphics) override;

        void handleEvent(SDL_Event* event) override;

//        Graphics* gGraphics;

#endif

    private:
        std::vector<Player*> gPlayers;

    };

}
