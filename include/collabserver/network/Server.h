#pragma once

#include <cstdint>
#include <string>
#include <memory> // unique_ptr

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageList.h"

namespace collab {


struct ServerConfig {
    uint16_t    port;
    std::string address;
};


/**
 * \brief
 * Server for network communication.
 *
 * \par Default settings
 *  - port: 4242
 */
class Server {
    private:
        bool        _isRunning  = false;
        std::string _address    = "*";
        uint16_t    _port       = 4242;

    public:
        Server() = default;
        Server(const ServerConfig& config);
        ~Server();

    public:
        void start();
        void stop();

    private:
        void handleMessage(const Message& msg);
        void handleMessage(const MsgDebug& msg);
        void handleMessage(const MsgConnectionRequest& msg);
};


} // End namespace

