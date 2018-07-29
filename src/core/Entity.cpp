//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include <iostream>
#include <client/Graphics.h>
#include "Entity.h"
#include "math/vector.h"
#include "Game.h"

namespace survivalist {

    Entity::Entity(const size &size, const vector &position) {}

    void Entity::setTexture(std::string name, Game* game) {
#ifdef GAME_CLIENT
        gTexture = game->gGraphics.gTextureHandler.getTexture(name);
#endif
    }

#ifdef GAME_CLIENT
    void Entity::render(SDL_Renderer* renderer) {

        SDL_Rect src_rect = { 0, 0, gSize.width, gSize.height };
        //SDL_Rect dst_rect = { gPosition.x, gPosition.y, gSize.width, gSize.height};
        SDL_Rect dst_rect = { 100, 100, 512, 512};

        SDL_RenderCopy(renderer, gTexture, NULL, NULL);
    }

#endif

}
