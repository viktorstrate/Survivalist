//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include "GameWorld.h"

namespace survivalist {

    GameWorld::GameWorld(Game* game)
            : gGame(game), player(Player(this, {128, 128})) {

    }

    void GameWorld::update(float dt) {

    }

#ifdef GAME_CLIENT
    void GameWorld::render(SDL_Renderer* renderer) {
        player.render(renderer);
    }


    void GameWorld::handleEvent(SDL_Event* event) {

    }
#endif

}