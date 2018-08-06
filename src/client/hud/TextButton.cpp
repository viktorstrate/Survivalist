//
// Created by Viktor Hundahl Strate on 06/08/2018.
//

#include <SDL.h>
#include "TextButton.h"
#include "client/Graphics.h"

namespace survivalist {

    TextButton::TextButton(const vector& position, const std::string &text)
            : Clickable(position, {static_cast<int>(text.length()*20), 32 }) {

    }

    void TextButton::render(Graphics* graphics) {

        SDL_Rect drawRect = {
                gPosition.getIntX(), gPosition.getIntY(),
                gSize.width, gSize.height
        };

        SDL_SetRenderDrawColor(graphics->getRenderer(), 0, 0, 0, 255);
        SDL_RenderFillRect(graphics->getRenderer(), &drawRect);
    }
}