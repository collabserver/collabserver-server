#include "network/Server.h"

#include <cjson/cJSON.h>

int main(int argc, char** argv) {
    collab::Server server;
    server.start();
    return 0;
}

