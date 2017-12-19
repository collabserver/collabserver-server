#pragma once

#include <zmq.hpp>


namespace collab {


/**
 * C++ proxy.
 *
 * \author  Constantin
 * \date    Dec 2017
 * \since   0.1.0
 */
class ServerProxy {
    private:
        zmq::context_t m_context;
        zmq::socket_t* m_socketSend = nullptr;
        std::string m_ip            = "localhost";
        int m_port                  = 0;
        bool m_isConnected          = false;

    public:
        ServerProxy() = default;
        ~ServerProxy();

    public:
        bool connect(const char* ip, const int port);
        bool disconnect();

    public:
        void createElt(const int id, const char* content) const;
        void readElt(const int id, const char* content) const;
        void updateElt(const int id, const char* content) const;
        void deleteElt(const int id) const;
};


} // End namespace
