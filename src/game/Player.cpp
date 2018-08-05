//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include <iostream>
#include "game/Player.h"
#include "game/GameWorld.h"

namespace survivalist {


    Player::Player(GameWorld* world, const vector &position, bool locallyControlled)
            : Entity({32, 32}, position), gLocallyControlled(locallyControlled), gWorld(world) {
        setTexture("player", world);
    }

    void Player::update(Uint32 dt) {

        InputHandler* inputHandler = &gWorld->gGraphics->gInputHandler;

        vector deltaSpeed = {
            inputHandler->getAxis("horizontal"), inputHandler->getAxis("vertical")
        };

        deltaSpeed = deltaSpeed * dt * gSpeed / 1000;

        gPosition = gPosition + deltaSpeed;
    }

    void Player::handleEvent(SDL_Event* event) {

    }
}
