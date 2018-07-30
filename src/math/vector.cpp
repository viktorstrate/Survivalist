//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include "math/vector.h"

namespace survivalist {

    vector operator+(const vector& lhs, const vector& rhs) {
        return {
                lhs.x + rhs.x,
                lhs.y + rhs.y
        };
    }

    bool operator==(const vector& lhs, const vector& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    vector operator-(const vector &lhs, const vector &rhs) {
        return {
            lhs.x - rhs.x,
            lhs.y - rhs.y
        };
    }

}