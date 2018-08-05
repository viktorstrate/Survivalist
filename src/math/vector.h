//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#pragma once

#include <iostream>

namespace survivalist {

    struct vector {
        double x, y;

        int getIntX() const {
            return static_cast<int>(x);
        }

        int getIntY() const {
            return static_cast<int>(y);
        }
    };

    vector operator*(const vector& lhs, const int& rhs);

    vector operator/(const vector& lhs, const int& rhs);

    std::ostream& operator<<(std::ostream &os, const vector& rhs);

    vector operator+(const vector& lhs, const vector& rhs);

    vector operator-(const vector& lhs, const vector& rhs);

    bool operator==(const vector& lhs, const vector& rhs);

}
