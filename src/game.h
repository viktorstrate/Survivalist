//
// Created by Viktor Strate on 14/07/16.
//

#ifndef SURVIVALIST_GAME_H
#define SURVIVALIST_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>

class Game {
public:
    Game();
    ~Game();
    const int WIDTH = 640;
    const int HEIGHT = 480;
    const float SCALE = 2.0f;

private:
    bool init();
    bool initOpenGL();
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_RendererInfo gRendererInfo;

};


#endif //SURVIVALIST_GAME_H
