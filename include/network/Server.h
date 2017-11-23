#pragma once

#include "message/Router.h"


namespace collab {


/**
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
class Server {
    private:
        bool isRunning;
        Router router;

    public:
        Server();
        ~Server();

    public:
        void start();
        void stop();
};


} // End namespace
