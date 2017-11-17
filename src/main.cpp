#include "network/Server.h"

#include <cjson/cJSON.h>
#include <logger/ElephantLogger.h>

int main(int argc, char** argv) {
    ElephantLogger::init();
    LOG_INFO(0, "Start server");
    collab::Server server;
    server.start();
    return 0;
}

