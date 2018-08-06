//
// Created by Viktor Hundahl Strate on 07/08/2018.
//

#include "MenuScreen.h"

namespace survivalist {

    MenuScreen::MenuScreen(Graphics* graphics)
            : World(graphics), playButton({20, 40}, "Play"), connectButton({20, 80}, "Connect to server") {}

    void MenuScreen::update(unsigned int dt) {
        playButton.update(dt);
        connectButton.update(dt);
    }

    void MenuScreen::render(Graphics* graphics) {
        playButton.render(graphics);
        connectButton.render(graphics);
    }

    void MenuScreen::handleEvent(SDL_Event* event) {
        playButton.handleEvent(event);
        connectButton.handleEvent(event);
    }

}
