//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include "GameWorld.h"

namespace survivalist {

    GameWorld::GameWorld(Game* game)
            : gGame(game), player(Player(this, {128, 128})) {

    }

    void GameWorld::update(Uint32 dt) {
        player.update(dt);
    }

#ifdef GAME_CLIENT
    void GameWorld::render(Graphics* graphics) {
        player.render(graphics);
    }


    void GameWorld::handleEvent(SDL_Event* event) {
        player.handleEvent(event);
    }
#endif

}