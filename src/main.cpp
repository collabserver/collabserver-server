#include <exception>
#include <iostream>

#include "collabserver/network/Server.h"
#include "collabcommon/utils/Log.h"


int main(int argc, char** argv) {
    LOG << "Program starts\n";

    try {
        collab::Server coco;
        coco.start();
    }
    catch(const std::exception& exception) {
        LOG << "Crashed with exception: " << exception.what() << std::endl;
        return -99;
    }
    catch(...) {
        LOG << "Crashed with unknown exception" << std::endl;
        return -100;
    }

    LOG << "Program ends\n";
    return 0;
}

