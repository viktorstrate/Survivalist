
#include <server/Server.h>
#include "client/Client.h"

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