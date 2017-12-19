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


ServerProxy::ServerProxy(const std::string & ip, const int port) 
    : m_ip(ip),
      m_port(port) {
    LOG_CONFIG(0, "Create Server Proxy (IP = %s / port = %d)", ip.c_str(), port);

    static zmq::socket_t zmqSocket(this->m_context, ZMQ_REQ); // TODO Change to SUB?
    this->m_socketSend = &zmqSocket;

    char buffer[100];
    snprintf(buffer, 99, "%s://%s:%d", "tcp", this->m_ip.c_str(), this->m_port);
    this->m_socketSend->connect(buffer); // ex: "tcp://localhost:5555"

    assert(port >= 0);
    assert(port <= 65535);
    assert(this->m_socketSend != nullptr);
}

ServerProxy::~ServerProxy() {
    this->shutdown();
    this->m_socketSend = nullptr;
}

void ServerProxy::startup() {
    LOG_CONFIG(0, "Startup ServerProxy");
    this->m_isRunning = true;
}

void ServerProxy::shutdown() {
    LOG_CONFIG(0, "Shutdown ServerProxy");
    this->m_isRunning = false;
}


// -----------------------------------------------------------------------------
// Core methods (Send to server)
// -----------------------------------------------------------------------------

void ServerProxy::createElt(const int id, const std::string & content) {
    LOG_DEBUG(0, "Proxy send 'create' message");
    if(this->m_isRunning) {
        MessageCreate msg;
        MessageHelper::sendMessage(*this->m_socketSend, msg);
    }
}

void ServerProxy::readElt(const int id, const std::string & content) {
    LOG_DEBUG(0, "Proxy send 'read' message");
    if(this->m_isRunning) {
        MessageRead msg;
        MessageHelper::sendMessage(*this->m_socketSend, msg);
    }
}

void ServerProxy::updateElt(const int id, const std::string & content) {
    LOG_DEBUG(0, "Proxy send 'update' message");
    if(this->m_isRunning) {
        MessageUpdate msg;
        MessageHelper::sendMessage(*this->m_socketSend, msg);
    }
}

void ServerProxy::deleteElt(const int id) {
    LOG_DEBUG(0, "Proxy send 'delete' message");
    if(this->m_isRunning) {
        MessageDelete msg;
        MessageHelper::sendMessage(*this->m_socketSend, msg);
    }
}
