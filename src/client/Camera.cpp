//
// Created by Viktor Hundahl Strate on 30/07/2018.
//

#include "Camera.h"

namespace survivalist {

    Camera::Camera(const vector &position, float scale) : gPosition(position), gScale(scale) {}

    vector Camera::worldToScreenSpace(const vector* worldSpace) {

        return *worldSpace - gPosition;

    }

    SDL_Rect Camera::drawDstRect(const vector* worldSpace, const size* srcSize) {
        vector screenPosition = worldToScreenSpace(worldSpace);

        return {
                static_cast<int>(screenPosition.getIntX()*gScale), static_cast<int>(screenPosition.getIntY()*gScale),
                static_cast<int>(srcSize->width * gScale), static_cast<int>(srcSize->height * gScale)
        };
    }

}