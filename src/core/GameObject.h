//
// Created by Viktor Hundahl Strate on 30/07/2018.
//

#pragma once

namespace survivalist {

    class Graphics;

    class GameObject {
    public:
        virtual void update(Uint32 dt) = 0;

#ifdef GAME_CLIENT
        virtual void render(Graphics* graphics) = 0;

        virtual void handleEvent(SDL_Event* event) {};
#endif
    };

}