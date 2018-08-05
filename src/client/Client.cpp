//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include <thread>
#include <iostream>

#include "Client.h"
#include "game/GameWorld.h"

using namespace std::literals::chrono_literals;

namespace survivalist {

    void Client::gameLoop() {
        while (!willQuit) {


            // Calculate delta time and sleep

            std::this_thread::sleep_for(8ms - std::chrono::milliseconds(SDL_GetTicks()));

            Uint32 currentUpdateTime = SDL_GetTicks();

            Uint32 deltaTime = currentUpdateTime - gPreviousUpdateTime;
            gPreviousUpdateTime = currentUpdateTime;

            // Rendering and updating

            gGraphics.update();
            gWorld->update(deltaTime);

        }
    }

    Client::Client() : gGraphics(this) {
        willQuit = false;


        gWorld = new GameWorld(&gGraphics);

        Player* mainPlayer = new Player(gWorld, {127, 127}, true);

        gWorld->spawnPlayer(mainPlayer);

        gameLoop();

        delete mainPlayer;
    }

    Client::~Client() {
        delete gWorld;
    }

    bool Client::connectToServer(const char* host, unsigned short port) {

        gClient = enet_host_create(NULL, 1, 2, 0, 0);

        enet_address_set_host(&gAddress, host);
        gAddress.port = port;

        gPeer = enet_host_connect(gClient, &gAddress, 2, 0);

        std::string hostDisplay = static_cast<std::string>(host) + ":" + std::to_string(port);

        if (gPeer == nullptr) {
            std::cerr << "ERROR: Could not connect to server: " << hostDisplay << std::endl;
            return false;
        }

        ENetEvent event;

        std::cout << "Waiting for response from server..." << std::endl;
        if (enet_host_service(gClient, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
            std::cout << "Successfully connected to " << hostDisplay << std::endl;
        } else {
            std::cerr << "ERROR: Could not connect to server" << std::endl;
            return false;
        }

        return true;
    }

}