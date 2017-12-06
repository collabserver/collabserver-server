#include "core/CollabServer.h"

#include <elephantlogger/log.h>

#include <exception>


int main(int argc, char** argv) {
    try {
        elephantlogger::init();
        elephantlogger::setDefaultChannels();

        LOG_TRACE(0, "Start Collab Server");

        collab::CollabServer& server = collab::CollabServer::getInstance();
        server.start();

        LOG_TRACE(0, "Start Collab Server");
    }
    catch(const std::exception& exception) {
        LOG_ERROR(0, "Crashed with exception: %s", exception.what());
        LOG_ERROR(3, "Crashed with exception: %s", exception.what());
        elephantlogger::saveLogs();
        return -99;
    }
    catch(...) {
        LOG_ERROR(0, "Crashed with unknown exception");
        LOG_ERROR(3, "Crashed with unknown exception");
        elephantlogger::saveLogs();
        return -100;
    }

    return 0;
}

