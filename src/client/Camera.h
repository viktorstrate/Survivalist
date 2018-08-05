//
// Created by Viktor Hundahl Strate on 30/07/2018.
//


#pragma once

#include <SDL_rect.h>

#include <math/vector.h>
#include <math/size.h>
#include <core/Entity.h>

namespace survivalist {

    class Camera {

    public:
        Camera(const vector &position, float scale);

        vector worldToScreenSpace(const vector* worldSpace);

        SDL_Rect drawDstRect(const vector* worldSpace, const size* srcSize);

    private:
        vector gPosition;
        float gScale;
    };

}