//
// Created by Viktor Strate on 14/07/16.
//

#include "Game.h"
#include "TextureHandler.h"
#include <iostream>
#include <SDL_image.h>

Game::Game(bool isServer, bool isClient) :
        willQuit(false),
        isServer(isServer),
        isClient(isClient) {

    if (isClient) {
        init_graphics();
    }

    main_loop();
}

bool Game::init_graphics() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Init: Failed " << std::endl << SDL_GetError() << std::endl;
        return false;
    }

    gWindow = SDL_CreateWindow("Survivalist", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int) (WIDTH*SCALE),
                               (int) (HEIGHT*SCALE), SDL_WINDOW_OPENGL);
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

    return true;
}

void Game::main_loop() {

    SDL_Event e;
    TextureHandler textureHandler(gRenderer);

    SDL_Texture* playerTexture = textureHandler.getTexture("player");

    while (!willQuit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                willQuit = true;
            }
        }


        SDL_Rect src = {0, 0, 32, 32};
        SDL_Rect dest = {100, 100, 512, 512};

        SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer, playerTexture, &src, &dest);
        SDL_RenderPresent(gRenderer);
    }
}

Game::~Game() {
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}







