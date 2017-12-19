#include "ServerProxy.h"

#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"
#include "messaging/MessageFactory.h"
#include "messaging/messages/MessageCreate.h"
#include "messaging/messages/MessageRead.h"
#include "messaging/messages/MessageUpdate.h"
#include "messaging/messages/MessageDelete.h"
#include "network/MessageHelper.h"

#include <cassert>
#include <zmq.hpp>
#include <elephantlogger/log.h>
#include <stdio.h>


using namespace collab;


ServerProxy::~ServerProxy() {
    this->disconnect();
}

bool ServerProxy::connect(const char* ip, const int port) {
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

void ServerProxy::createElt(const int id, const char* content) const {
    LOG_DEBUG(0, "Proxy sends 'create' message");
    if(this->m_isConnected) {
        MessageCreate msg;
        MessageHelper::sendMessage(*this->m_socketSend, msg);
    }
}

void ServerProxy::readElt(const int id, const char* content) const {
    LOG_DEBUG(0, "Proxy sends 'read' message");
    if(this->m_isConnected) {
        MessageRead msg;
        MessageHelper::sendMessage(*this->m_socketSend, msg);
    }
}

void ServerProxy::updateElt(const int id, const char* content) const {
    LOG_DEBUG(0, "Proxy sends 'update' message");
    if(this->m_isConnected) {
        MessageUpdate msg;
        MessageHelper::sendMessage(*this->m_socketSend, msg);
    }
}

void ServerProxy::deleteElt(const int id) const {
    LOG_DEBUG(0, "Proxy sends 'delete' message");
    if(this->m_isConnected) {
        MessageDelete msg;
        MessageHelper::sendMessage(*this->m_socketSend, msg);
    }
}
