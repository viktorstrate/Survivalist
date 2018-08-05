//
// Created by Viktor Hundahl Strate on 29/07/2018.
//

#include "vector.h"

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

    vector operator*(const vector &lhs, const int &rhs) {
        return vector({
                lhs.x * rhs,
                lhs.y * rhs
        });
    }

    vector operator/(const vector &lhs, const int &rhs) {
        return {
            lhs.x / rhs,
            lhs.y / rhs
        };
    }

    std::ostream &operator<<(std::ostream &os, const vector &vector) {
        return os << vector.x << ", " << vector.y;
    }

    vector vector::lerp(const vector &a, const vector &b, double amount) {
        return {
            (1 - amount) * a.x + amount * b.x,
            (1 - amount) * a.y + amount * b.y
        };
    }
}