#include "network/Server.h"

#include <cjson/cJSON.h>
#include <logger/ElephantLogger.h>

int main(int argc, char** argv) {
    collab::Server server;
    server.start();
    return 0;
}

