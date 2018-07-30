//
// Created by Viktor Hundahl Strate on 30/07/2018.
//

#include "Camera.h"

namespace survivalist {

    Camera::Camera(const vector &position, float scale) : gPosition(position), gScale(scale) {}

    vector Camera::worldToScreenSpace(survivalist::vector worldSpace) {

        return worldSpace - gPosition;

    }

    SDL_Rect Camera::drawDstRect(vector worldSpace, size srcSize) {
        vector screenPosition = worldToScreenSpace(worldSpace);

        return {
                screenPosition.x, screenPosition.y,
                static_cast<int>(srcSize.width*gScale), static_cast<int>(srcSize.height*gScale)
        };
    }

}