//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include <iostream>
#include <client/Graphics.h>
#include "Entity.h"
#include "math/vector.h"
#include "Game.h"

namespace survivalist {

    Entity::Entity(const size &size, const vector &position)
            : gSize(size), gPosition(position) {}

    void Entity::setTexture(std::string name, Game* game) {
#ifdef GAME_CLIENT
        gTexture = game->gGraphics.gTextureHandler.getTexture(name);
#endif
    }

#ifdef GAME_CLIENT
    void Entity::render(SDL_Renderer* renderer) {

        SDL_Rect src_rect = { 0, 0, gSize.width, gSize.height };
        SDL_Rect dst_rect = { gPosition.x, gPosition.y, gSize.width * Graphics::SCALE, gSize.height * Graphics::SCALE};

        SDL_RenderCopy(renderer, gTexture, &src_rect, &dst_rect);
    }

#endif

}
