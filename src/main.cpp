#include "collabserver/network/MessageListener.h"

#include <exception>
#include <iostream>

#include "collabcommon/utils/Log.h"


int main(int argc, char** argv) {
    try {
        // TODO This is temporary test
        LOG << "DEBUG: Start server\n";
        collab::MessageListener coco;
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

    return 0;
}

