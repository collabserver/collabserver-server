#include "collabserver/network/MessageListener.h"

#include <exception>
#include <iostream>


int main(int argc, char** argv) {
    try {
        // TODO This is temporary test
        std::clog << "DEBUG: Start server\n";
        collab::MessageListener coco;
        coco.start();
        std::clog << "DEBUG: Stop server\n";
    }
    catch(const std::exception& exception) {
        std::clog << "Crashed with exception: " << exception.what() << std::endl;
        return -99;
    }
    catch(...) {
        std::clog << "Crashed with unknown exception" << std::endl;
        return -100;
    }

    return 0;
}

