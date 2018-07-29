//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include "game/Player.h"
#include "game/GameWorld.h"

namespace survivalist {


    Player::Player(GameWorld* world, const vector &position)
            : Entity({32, 32}, position) {
        setTexture("player", world->gGame);
    }
}
