//
// Created by Viktor Hundahl Strate on 30/07/2018.
//


#pragma once

#include <math/vector.h>
#include <math/size.h>
#include <SDL_rect.h>

namespace survivalist {

    class Camera {

    public:
        Camera(const vector &position, float scale);

        vector worldToScreenSpace(vector worldSpace);

        SDL_Rect drawDstRect(vector worldSpace, size srcSize);

    private:
        vector gPosition;
        float gScale;
    };

}