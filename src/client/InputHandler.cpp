//
// Created by Viktor Hundahl Strate on 31/07/2018.
//

#include <iostream>
#include "InputHandler.h"

namespace survivalist {
    InputHandler::InputHandler() {

        gAxisStates["horizontal"] = 0.f;
        gAxisStates["vertical"] = 0.f;

    }

    float InputHandler::getAxis(std::string axis) {
        return gAxisStates[axis];
    }

    bool InputHandler::getButton(std::string button) {
        return gButtonStates[button];
    }

    void InputHandler::handleEvent(SDL_Event* event) {
        if (event->type == SDL_KEYDOWN) {

            std::cout << "Key press down" << std::endl;

            switch (event->key.keysym.sym) {
                case SDLK_w:
                    gAxisStates["vertical"] = -1.f;
                    break;
                case SDLK_s:
                    gAxisStates["vertical"] = 1.f;
                    break;
                case SDLK_d:
                    gAxisStates["horizontal"] = 1.f;
                    break;
                case SDLK_a:
                    gAxisStates["horizontal"] = -1.f;
                    break;
                default:
                    break;
            }

        }

        if (event->type == SDL_KEYUP) {

            std::cout << "Key press up" << std::endl;

            switch (event->key.keysym.sym) {
                case SDLK_w:
                    if (gAxisStates["vertical"] < 0) {
                        gAxisStates["vertical"] = 0;
                    }
                    break;
                case SDLK_s:
                    if (gAxisStates["vertical"] > 0) {
                        gAxisStates["vertical"] = 0;
                    }
                    break;
                case SDLK_d:
                    if (gAxisStates["horizontal"] > 0) {
                        gAxisStates["horizontal"] = 0;
                    }
                    break;
                case SDLK_a:
                    if (gAxisStates["horizontal"] < 0) {
                        gAxisStates["horizontal"] = 0;
                    }
                    break;
                default:
                    break;
            }

        }
    }
}
