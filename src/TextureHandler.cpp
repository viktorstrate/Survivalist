//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include "TextureHandler.h"
#include <SDL_image.h>
#include <iostream>


TextureHandler::TextureHandler(SDL_Renderer* renderer):
    gRenderer(renderer) {}

SDL_Texture* TextureHandler::getTexture(std::string name) {

    SDL_Texture* lookupTexture = gTextures[name];

    if (lookupTexture != nullptr) {
        return lookupTexture;
    }

    std::string path = "assets/" + name + ".png";
    SDL_Surface* surface = IMG_Load(path.c_str());

    if (surface == nullptr) {
        std::cerr << "Error loading texture at path: '" << path << "'! SDL Image Error:"
                                                                   << std::endl << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, surface);
    gTextures[name] = texture;

    return texture;
}
