#pragma once

#include "messaging/MessageRouter.h"


namespace collab {

//class MessageRouter;


/**
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
class Server {
    private:
        bool m_isRunning;
        MessageRouter m_messageRouter;

    public:
        Server();
        ~Server();

    public:
        void start();
        void stop();
};


} // End namespace
