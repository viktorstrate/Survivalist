//
// Created by Viktor Hundahl Strate on 06/08/2018.
//


#pragma once

#include <string>
#include "Clickable.h"
#include "math/vector.h"

namespace survivalist {

    class TextButton : public Clickable {
    public:
        TextButton(const vector& position, const std::string& text);

        void render(Graphics* graphics) override;

        std::string gText;

    };

}
