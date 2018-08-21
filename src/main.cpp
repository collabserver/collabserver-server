#include <csignal>
#include <cstdlib>
#include <exception>
#include <iostream>

#include "collabserver/network/Server.h"
#include "collabcommon/utils/Log.h"


static collab::Server server;

static void handleInterrupt(int i) {
    LOG << "SIGINT received. Closing server...\n";
    server.stop();
}

int main(int argc, char** argv) {
    signal(SIGINT, &handleInterrupt);

    LOG << "Starts CollabServer\n";

    try {
        server.start();
    }
    catch(const std::exception& exception) {
        server.stop();
        LOG << "Crashed with exception: " << exception.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch(...) {
        server.stop();
        LOG << "Crashed with unknown exception" << std::endl;
        return EXIT_FAILURE;
    }

    LOG << "Close CollabServer\n";
    return EXIT_SUCCESS;
}

