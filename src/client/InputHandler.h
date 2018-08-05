//
// Created by Viktor Hundahl Strate on 31/07/2018.
//


#pragma once

#include <string>
#include <unordered_map>
#include <SDL_events.h>

namespace survivalist {

    class InputHandler {

    public:

        InputHandler();

        float getAxis(std::string axis);

        bool getButton(std::string button);

        void handleEvent(SDL_Event* event);

    private:

        std::unordered_map<std::string, bool> gButtonStates;
        std::unordered_map<std::string, float> gAxisStates;

    };

}
