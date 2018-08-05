//
// Created by Viktor Hundahl Strate on 30/07/2018.
//

#include "Camera.h"
#include "Graphics.h"

namespace survivalist {

    Camera::Camera(const vector &position, float scale, Graphics* graphics) : gPosition(position), gScale(scale), gGraphics(graphics) {}

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

    void Camera::update(unsigned int dt) {
        if (gFollowingEntity != nullptr) {

            vector target = gFollowingEntity->gPosition
                    - vector({
                        gGraphics->WIDTH / 2.0 / gScale,
                        gGraphics->HEIGHT / 2.0 / gScale
                    });

            target = target + vector({
                        gFollowingEntity->getSize().width / 2.0,
                        gFollowingEntity->getSize().height / 2.0
                    });

            gPosition = vector::lerp(gPosition, target, 4.0 * dt / 1000.0);
        }
    }

}