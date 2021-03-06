//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include "GameWorld.h"
#include "game/Player.h"

namespace survivalist {

    void GameWorld::update(unsigned int dt) {
        for (Player* player : gPlayers) {
            player->update(dt);
        }
    }

    void GameWorld::init() {

#ifdef GAME_CLIENT
        Player* mainPlayer = new Player(this, {127, 127}, true);

        spawnPlayer(mainPlayer);
        gGraphics->gCamera.gFollowingEntity = mainPlayer;
#endif
    }

    void GameWorld::spawnPlayer(Player* player) {
        gPlayers.push_back(player);
    }

#ifdef GAME_SERVER
    GameWorld::GameWorld() : World() {
        init();
    }
#endif

    GameWorld::~GameWorld() {
        for (Player* player : gPlayers) {
            delete player;
        }
    }

#ifdef GAME_CLIENT

    void GameWorld::render(Graphics* graphics) {
        for (Player* player : gPlayers) {
            player->render(graphics);
        }
    }


    void GameWorld::handleEvent(SDL_Event* event) {
        for (Player* player : gPlayers) {
            player->handleEvent(event);
        }
    }

    GameWorld::GameWorld(Graphics* graphics) : World(graphics) {
        init();
    }

#endif

}