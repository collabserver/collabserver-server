#include "ServerProxy.h"

#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"
#include "messaging/MessageFactory.h"

#include <cassert>
#include <zmq.hpp>
#include <elephantlogger/log.h>


using namespace collab;


ServerProxy::ServerProxy(const std::string ip, const int port) 
    : m_ip(ip),
      m_port(port) {
    assert(port >= 0);
    assert(port <= 65535);
    LOG_CONFIG(0, "Create Server Proxy (IP = %s / port = %d)", ip.c_str(), port);
}

ServerProxy::~ServerProxy() {
    this->shutdown();
}

void ServerProxy::startup() {
    LOG_CONFIG(0, "Startup ServerProxy");
    this->m_isRunning = true;
}

void ServerProxy::shutdown() {
    LOG_CONFIG(0, "Shutdown ServerProxy");
    this->m_isRunning = false;
}

void ServerProxy::createElt(const int id, const std::string & content) {
    LOG_DEBUG(0, "Proxy send 'create' message");
    if(this->m_isRunning) {
        IMessage* msg = MessageFactory::getInstance().newMessage(static_cast<int>(MessageTypes::Create));
        assert(msg != nullptr);
        if(msg == nullptr) {
            LOG_WTF(0, "MessageFactory returned null msg for type 'Create'");
            return;
        }
    }
}

void ServerProxy::readElt(const int id, const std::string & content) {
    LOG_DEBUG(0, "Proxy send 'read' message");
}

void ServerProxy::updateElt(const int id, const std::string & content) {
    LOG_DEBUG(0, "Proxy send 'update' message");
}

void ServerProxy::deleteElt(const int id) {
    LOG_DEBUG(0, "Proxy send 'delete' message");
}
