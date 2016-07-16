//
// Created by Viktor Strate on 14/07/16.
//

#include "Game.h"

Game::Game() {
    init();
}

bool Game::init() {

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cerr << "SDL Init: Failed " << std::endl << SDL_GetError() << std::endl;
        return false;
    } else {
        std::cout << "SDL Init: Success" << std::endl;
    }

    gWindow = SDL_CreateWindow("Survivalist", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int) (WIDTH * SCALE),
                               (int) (HEIGHT * SCALE), SDL_WINDOW_OPENGL);
    if(gWindow == NULL){
        std::cerr << "SDL Create Window: Failed " << std::endl << SDL_GetError() << std::endl;
        return false;
    } else {
        std::cout << "SDL Create Window: Success" << std::endl;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

    if(gRenderer == NULL){
        std::cerr << "SDL Create Renderer: Failed " << std::endl << SDL_GetError() << std::endl;
        return false;
    } else {
        std::cout << "SDL Create Renderer: Success" << std::endl;
    }

    SDL_GetRendererInfo(gRenderer, &gRendererInfo);




    return true;
}

Game::~Game() {

}

bool Game::initOpenGL() {

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    return true;
}







