#pragma once

#include <cstdint>
#include <string>

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
};


} // End namespace

