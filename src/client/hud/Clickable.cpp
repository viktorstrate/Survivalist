//
// Created by Viktor Hundahl Strate on 06/08/2018.
//

#include "Clickable.h"
#include <iostream>

namespace survivalist {

    void Clickable::handleEvent(SDL_Event* event) {
        if (event->type == SDL_MOUSEBUTTONUP) {

            SDL_MouseButtonEvent& mouseEvent = event->button;

            if (mouseEvent.x >= gPosition.getIntX() && mouseEvent.x <= gPosition.getIntX() + gSize.width
                    && mouseEvent.y >= gPosition.getIntY() && mouseEvent.y <= gPosition.getIntY() + gSize.height) {

                if (mouseEvent.state == SDL_RELEASED) {
                    onClick(&mouseEvent);
                }

            }
        }
    }

    Clickable::Clickable(const vector &position, const size &size) : gSize(size), gPosition(position) {}

    void Clickable::update(Uint32 dt) {}

}