
#include <cstdint>

#ifdef GAME_CLIENT
#include "client/Client.h"
#endif

#ifdef GAME_SERVER
#include "server/Server.h"
#endif

using namespace survivalist;

int main() {

#ifdef GAME_CLIENT
    Client game;
#endif

#ifdef GAME_SERVER
    Server server;
#endif

    return 0;
}