//
// Created by Viktor Hundahl Strate on 07/08/2018.
//


#pragma once

#include "client/Client.h"
#include "core/World.h"
#include "client/hud/TextButton.h"

namespace survivalist {

    class MenuScreen : public World {
    public:
        MenuScreen(Client* client);

        void update(unsigned int dt) override;

        void render(Graphics* graphics) override;

        void handleEvent(SDL_Event* event) override;

    private:
        TextButton playButton;
        TextButton connectButton;

        Client* gClient;

    };

}

