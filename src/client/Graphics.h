//
// Created by Viktor Strate on 14/07/16.
//

#pragma once

#include <SDL.h>
#include "core/World.h"
#include "TextureHandler.h"

namespace survivalist {

    class Game;

    class Graphics {
    public:
        explicit Graphics(Game* game);
        ~Graphics();

        void update();

        static const int WIDTH = 480;
        static const int HEIGHT = 360;
        static const int SCALE = 2;

        TextureHandler gTextureHandler = NULL;

    private:

        bool init_graphics();

        Game* gGame;

        SDL_Window* gWindow;
        SDL_Renderer* gRenderer;

    };

}
