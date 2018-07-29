//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include "Game.h"
#include "game/GameWorld.h"

namespace survivalist {

    void Game::gameLoop() {
        while (!willQuit) {

#ifdef GAME_CLIENT
            gGraphics.update();
#endif

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
