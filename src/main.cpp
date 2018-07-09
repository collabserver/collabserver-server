#include <exception>
#include <iostream>

#include "collabcommon/utils/Log.h"
#include "collabserver/network/Server.h"
#include "collabcommon/network/Network.h"


int main(int argc, char** argv) {
    collab::network::initializeNetwork();

    try {
        // TODO This is temporary test
        LOG << "DEBUG: Start server\n";
        collab::Server coco;
        coco.start();
        LOG << "DEBUG: Stop server\n";
    }
    catch(const std::exception& exception) {
        LOG << "Crashed with exception: " << exception.what() << std::endl;
        return -99;
    }
    catch(...) {
        LOG << "Crashed with unknown exception" << std::endl;
        return -100;
    }

    collab::network::shutdownNetwork();

    return 0;
}

