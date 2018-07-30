//
// Created by Viktor Strate on 14/07/16.
//

#include <iostream>
#include <SDL_image.h>

#include "core/Game.h"
#include "client/Graphics.h"
#include "client/TextureHandler.h"
#include "game/GameWorld.h"

namespace survivalist {

    Graphics::Graphics(Game* game) : gGame(game), gCamera({0, 0}, 2) {
        std::cout << "Initializing game..." << std::endl;
        init_graphics();
    }

    bool Graphics::init_graphics() {

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL Init: Failed " << std::endl << SDL_GetError() << std::endl;
            return false;
        }

        gWindow = SDL_CreateWindow("Survivalist", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,
                                   HEIGHT, SDL_WINDOW_OPENGL);
        if (gWindow == nullptr) {
            std::cerr << "SDL Create Window: Failed " << std::endl << SDL_GetError() << std::endl;
            return false;
        }

        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

        if (gRenderer == nullptr) {
            std::cerr << "SDL Create Renderer: Failed" << std::endl << SDL_GetError() << std::endl;
            return false;
        }

        SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);

        int imageFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imageFlags) & imageFlags)) {
            std::cerr << "SDL Image Initialization: Failed" << std::endl << IMG_GetError() << std::endl;
            return false;
        }

        gTextureHandler = TextureHandler(gRenderer);

        std::cout << "Graphics successfully initialized" << std::endl;
        return true;
    }

    Graphics::~Graphics() {

        SDL_DestroyWindow(gWindow);
        SDL_Quit();
    }

    void Graphics::update() {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                gGame->willQuit = true;
            }
        }

        SDL_RenderClear(gRenderer);

        gGame->gWorld->render(this);

        SDL_RenderPresent(gRenderer);
    }

    SDL_Renderer* Graphics::getRenderer() const {
        return gRenderer;
    }

}
