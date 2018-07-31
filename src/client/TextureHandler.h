//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

#include <SDL.h>
#include <unordered_map>
#include <string>

namespace survivalist {

    class TextureHandler {
    public:
        explicit TextureHandler(SDL_Renderer* renderer);
        TextureHandler() = default;

        SDL_Texture* getTexture(std::string name);

    private:
        SDL_Renderer* gRenderer = nullptr;
        std::unordered_map<std::string, SDL_Texture*> gTextures;

    };

}
