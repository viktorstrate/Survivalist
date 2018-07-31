//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include <chrono>
#include <iostream>

#include "Client.h"
#include "game/GameWorld.h"

namespace survivalist {

    void Client::gameLoop() {
        while (!willQuit) {

            gGraphics.update();

            Uint32 currentUpdateTime = SDL_GetTicks();
            Uint32 deltaTime = currentUpdateTime - gPreviousUpdateTime;
            gPreviousUpdateTime = currentUpdateTime;

            gWorld->update(deltaTime);

        }
    }

    Client::Client() : gGraphics(this) {
        willQuit = false;

        gWorld = new GameWorld(&gGraphics);

        gameLoop();
    }

    Client::~Client() {
        delete gWorld;
    }

}
