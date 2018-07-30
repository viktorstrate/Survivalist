//
// Created by Viktor Strate on 14/07/16.
//

#pragma once

#include <SDL.h>
#include "core/World.h"
#include "TextureHandler.h"
#include "Camera.h"

namespace survivalist {

    class Game;

    class Graphics {
    public:
        explicit Graphics(Game* game);
        ~Graphics();

        void update();

        SDL_Renderer* getRenderer() const;

        static const int WIDTH = 720;
        static const int HEIGHT = 480;

        TextureHandler gTextureHandler = NULL;
        Camera gCamera;

    private:

        bool init_graphics();

        Game* gGame;

        SDL_Window* gWindow;
        SDL_Renderer* gRenderer;

    };

}
