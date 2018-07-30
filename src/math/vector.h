//
// Created by Viktor Hundahl Strate on 29/07/2018.
//


#pragma once

namespace survivalist {

    struct vector {
        int x, y;
    };

    vector operator+(const vector& lhs, const vector& rhs);

    vector operator-(const vector& lhs, const vector& rhs);

    bool operator==(const vector& lhs, const vector& rhs);

}
