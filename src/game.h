//
// Created by Viktor Strate on 14/07/16.
//

#pragma once

#include <SDL.h>

class Game {
public:
    explicit Game(bool isServer, bool isClient);
    ~Game();
    const int WIDTH = 480;
    const int HEIGHT = 360;
    const float SCALE = 2.0f;

private:
    bool init_graphics();
    void main_loop();

    bool isServer;
    bool isClient;
    bool willQuit;

    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;

};

