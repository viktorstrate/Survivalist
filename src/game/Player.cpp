//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include <iostream>
#include "game/Player.h"
#include "game/GameWorld.h"

namespace survivalist {


    Player::Player(GameWorld* world, const vector &position)
            : Entity({32, 32}, position) {
        setTexture("player", world);
    }

    void Player::update(Uint32 dt) {
        std::cout << "Player update delta time: " << dt << std::endl;
    }
}
