//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include <chrono>
#include <iostream>

#include "Server.h"
#include "game/GameWorld.h"

namespace survivalist {

    void Server::gameLoop() {
        while (!willQuit) {


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

            gWorld->update(deltaTime);

        }
    }

    Server::Server() {
        willQuit = false;

        gWorld = new GameWorld();

        gameLoop();
    }

    Server::~Server() {
        delete gWorld;
    }

}
