//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include "GameWorld.h"

namespace survivalist {

#ifdef GAME_SERVER
    GameWorld::GameWorld() {
        init();
    }
#endif

    void GameWorld::update(Uint32 dt) {
        for (Player player : players) {
            player.update(dt);
        }
    }

    void GameWorld::init() {

    }

#ifdef GAME_CLIENT

    void GameWorld::render(Graphics* graphics) {
        for (Player player : players) {
            player.render(graphics);
        }
    }


    void GameWorld::handleEvent(SDL_Event* event) {
        for (Player player : players) {
            player.handleEvent(event);
        }
    }

    GameWorld::GameWorld(Graphics* graphics) : World(graphics) {
        init();
    }

#endif

}