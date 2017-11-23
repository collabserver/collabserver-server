#include "network/Server.h"

#include <cjson/cJSON.h>
#include <logger/elephant.h>

int main(int argc, char** argv) {
    elephant::init();

    LOG_TRACE(0, "Start Collab Server");

    collab::Server server;
    server.start();

    LOG_TRACE(0, "Start Collab Server");
    return 0;
}

