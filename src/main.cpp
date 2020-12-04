#include <csignal>
#include <cstdlib>
#include <exception>
#include <iostream>

#include "collabcommon/utils/Log.h"
#include "collabserver/network/Server.h"

static collab::Server* server_ptr = nullptr;

static void handleInterrupt(int i) {
    LOG << "SIGINT received. Closing server...\n";
    server_ptr->stop();
}

int main(int argc, char** argv) {
    signal(SIGINT, &handleInterrupt);

    collab::Server server;
    server_ptr = &server;

    LOG << "Starts CollabServer\n";

    try {
        server.start();
    } catch (const std::exception& exception) {
        server.stop();
        LOG << "Crashed with exception: " << exception.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        server.stop();
        LOG << "Crashed with unknown exception" << std::endl;
        return EXIT_FAILURE;
    }

    LOG << "Close CollabServer\n";
    return EXIT_SUCCESS;
}
