//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include <chrono>
#include <iostream>

#include "Game.h"
#include "game/GameWorld.h"

namespace survivalist {

    void Game::gameLoop() {
        while (!willQuit) {

#ifdef GAME_CLIENT
            gGraphics.update();

            Uint32 currentUpdateTime = SDL_GetTicks();
            Uint32 deltaTime = currentUpdateTime - gPreviousUpdateTime;
            gPreviousUpdateTime = currentUpdateTime;

#elif defined(GAME_SERVER)

            Uint32 deltaTime;
            auto currentUpdateTime = std::chrono::high_resolution_clock::now();

            do {

                currentUpdateTime = std::chrono::high_resolution_clock::now();

                if (gPreviousUpdateTime.time_since_epoch().count() == 0) {
                    gPreviousUpdateTime = currentUpdateTime;
                }

                std::chrono::duration<float> difference = currentUpdateTime - gPreviousUpdateTime;

                deltaTime = static_cast<Uint32>(difference.count()*1000.f);

            } while (deltaTime < 16);

            gPreviousUpdateTime = currentUpdateTime;

#endif

            gWorld->update(deltaTime);

        }
    }

    Game::Game()
#ifdef GAME_CLIENT
    : gGraphics(this)
#endif
    {
        willQuit = false;

        gWorld = new GameWorld(this);

        gameLoop();
    }

    Game::~Game() {
        delete gWorld;
    }

}
