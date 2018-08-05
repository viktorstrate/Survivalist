//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

namespace survivalist {

    struct vector {
        double x, y;

        int getIntX() {
            return static_cast<int>(x);
        }

        int getIntY() {
            return static_cast<int>(y);
        }
    };

    vector operator+(const vector& lhs, const vector& rhs);

    vector operator-(const vector& lhs, const vector& rhs);

    bool operator==(const vector& lhs, const vector& rhs);

}
