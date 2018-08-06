//
// Created by Viktor Hundahl Strate on 06/08/2018.
//

#include "Clickable.h"
#include <iostream>

namespace survivalist {

    void Clickable::handleEvent(SDL_Event* event) {
        if (event->type == SDL_MOUSEBUTTONUP) {

            SDL_MouseButtonEvent& mouseEvent = event->button;

            if (mouseEvent.state == SDL_RELEASED) {
                std::cout << "Mouse released" << std::endl;
            }
        }
    }

    Clickable::Clickable(const vector &position, const size &size) : gSize(size), gPosition(position) {}

    void Clickable::update(Uint32 dt) {}

}