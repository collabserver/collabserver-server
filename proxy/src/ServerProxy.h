#pragma once

#include "util/Singleton.h"

#include <zmq.hpp>


namespace collab {
class IMessage;


/**
 * C++ network proxy connection.
 *
 * \author  Constantin
 * \date    Dec 2017
 * \since   0.1.0
 */
class ServerProxy : private Singleton<ServerProxy> {

    // Singleton elements
    private:
        friend Singleton<ServerProxy>;
        ServerProxy() = default;
        ~ServerProxy() = default;
    public:
        using Singleton<ServerProxy>::getInstance;


    private:
        zmq::context_t m_context;
        zmq::socket_t* m_socketSend = nullptr;
        std::string m_ip            = "localhost";
        int m_port                  = 0;
        bool m_isConnected          = false;

    public:
        bool connect(const char* ip, const int port, const float timeout = 0.0f);
        bool disconnect();
        void sendMessage(const IMessage & msg);

    public:
        bool isConnected() const;
};


} // End namespace
