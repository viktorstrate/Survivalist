//
// Created by Viktor Strate on 14/07/16.
//

#pragma once

#include <SDL.h>
#include "TextureHandler.h"
#include "Camera.h"
#include "InputHandler.h"

namespace survivalist {

    class Client;

    class Graphics {
    public:
        explicit Graphics(Client* client);
        ~Graphics();

        void update(unsigned int dt);

        SDL_Renderer* getRenderer() const;

        static const int WIDTH = 720;
        static const int HEIGHT = 480;

        TextureHandler gTextureHandler;
        InputHandler gInputHandler;

        Camera gCamera;

    private:

        bool init_graphics();

        Client* gClient;

        SDL_Window* gWindow;
        SDL_Renderer* gRenderer;

    };

}
