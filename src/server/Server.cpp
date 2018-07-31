//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include <chrono>
#include <iostream>
#include <thread>

#include "Server.h"
#include "game/GameWorld.h"

using namespace std::literals::chrono_literals;

namespace survivalist {

    void Server::gameLoop() {

        std::cout << "Main game loop started" << std::endl;

        Uint32 deltaTime = 0;

        while (!willQuit) {

//            std::chrono::time_point<std::chrono::high_resolution_clock> currentUpdateTime;

            auto currentUpdateTime = std::chrono::high_resolution_clock::now();

            if (gPreviousUpdateTime.time_since_epoch().count() == 0) {
                std::cout << "First update" << std::endl;
                gPreviousUpdateTime = currentUpdateTime;
            }

            std::chrono::duration<float> difference = currentUpdateTime - gPreviousUpdateTime;


            std::this_thread::sleep_for(16ms - difference);

            difference = std::chrono::high_resolution_clock::now() - gPreviousUpdateTime;
            deltaTime = static_cast<Uint32>(difference.count()*1000.f);

            gPreviousUpdateTime = currentUpdateTime;


            gWorld->update(deltaTime);

            ENetEvent event;

            while (enet_host_service(gHost, &event, 10000) > 0) {
                std::cout << "Received ENet event: " << event.type << std::endl;
            }

        }
    }

    Server::Server() : gAddress(), gHost() {
        willQuit = false;

        if (enet_initialize() != 0) {
            std::cerr << "ERROR: Could not initialize ENet" << std::endl;
            return;
        }

        gAddress.host = ENET_HOST_ANY;
        gAddress.port = 1235;

        gHost = enet_host_create(&gAddress, 32, 2, 0, 0);

        if (gHost == nullptr) {
            std::cerr << "ERROR: Could not create server host" << std::endl;
            return;
        }

        gWorld = new GameWorld();

        gameLoop();
    }

    Server::~Server() {
        enet_deinitialize();
        enet_host_destroy(gHost);
        delete gWorld;
    }

}
