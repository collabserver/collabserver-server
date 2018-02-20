#include "ServerProxy.h"

#include "network/NetHelper.h"

#include <cassert>
#include <zmq.hpp>
#include <stdio.h>
#include <elephantlogger/log.h>


using namespace collab;


ServerProxy::~ServerProxy() {
    this->disconnect();
}

bool ServerProxy::connect(const char* ip, const int port) {
    assert(this->m_isConnected == false);
    if(this->m_isConnected) {
        LOG_TRACE(0, "Proxy already connected.");
        return false;
    }

    LOG_TRACE(0, "Try to connect proxy to %s:%d", ip, port);

    static zmq::socket_t zmqSocket(this->m_context, ZMQ_REQ);

    this->m_socketSend  = &zmqSocket;
    this->m_ip          = std::string(ip);
    this->m_port        = port;

    char buffer[256];
    snprintf(buffer, 255, "%s://%s:%d", "tcp", ip, port);
    this->m_socketSend->connect(buffer); // ex: "tcp://localhost:5555"
    this->m_isConnected = true;

    assert(port >= 0);
    assert(port <= 65535);
    assert(this->m_socketSend != nullptr);
    return true;
}

bool ServerProxy::disconnect() {
    if(!this->m_isConnected) {
        return false;
    }
    this->m_isConnected = false;
    char buffer[256];
    snprintf(buffer, 255, "%s://%s:%d", "tcp", this->m_ip.c_str(), this->m_port);
    const int res = zmq_disconnect(this->m_socketSend, buffer);
    return res == 0 ? true : false;
}


// -----------------------------------------------------------------------------
// Core methods (Send to server)
// -----------------------------------------------------------------------------


/*
void ServerProxy::readElt(const int id, const char* content) const {
    LOG_DEBUG(0, "Proxy sends 'read' message");
    if(this->m_isConnected) {
        MessageRead msg;
        NetHelper::sendMessage(*this->m_socketSend, msg);
        zmq::message_t request;
        this->m_socketSend->recv(&request);
    }
}
*/
