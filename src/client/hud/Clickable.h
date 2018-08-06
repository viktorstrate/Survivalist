//
// Created by Viktor Hundahl Strate on 06/08/2018.
//


#pragma once

#include <SDL_events.h>
#include <math/vector.h>
#include "math/size.h"
#include "core/GameObject.h"

namespace survivalist {

    class Clickable : public GameObject {

    public:
        Clickable(const vector &position, const size &size);

        virtual void onClick() {};

        size gSize;
        vector gPosition;

        void update(Uint32 dt) override;

        void handleEvent(SDL_Event* event) override;

    };

}
