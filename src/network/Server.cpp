#include "collabserver/network/Server.h"

#include <cassert>
#include <zmq.hpp>

#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/network/ZMQSocket.h"
#include "collabcommon/utils/Log.h"

namespace collab {


// TODO Tmp placed here
static ZMQSocketConfig config = {
    ZMQ_REP,
    &g_context,
    &(MessageFactory::getInstance())
};
static ZMQSocket socket(config);


Server::Server() {
    _collabserver = new CollabServer(*this);
}

Server::Server(const ServerConfig& config) : Server() {
    _port       = config.port;
}

Server::~Server() {
    this->stop();
    delete _collabserver;
}

void Server::start() {
    assert(_isRunning == false);
    if(_isRunning) {
        return;
    }
    _isRunning = true;
    LOG << "Starting network server\n";

    LOG << "Binding socket: (" << _address << ", " << _port << ")\n";
    socket.bind(_address.c_str(), _port);
    LOG << "Socket successfully binded\n";

    while(_isRunning) {
        LOG << "Waiting for any message\n";
        Message* msg = socket.receiveMessage();
        assert(msg != nullptr);
        this->handleMessage(*msg);
        MessageFactory::getInstance().freeMessage(msg);
    }

    socket.unbind();
}

void Server::stop() {
    this->_isRunning = false;
}

void Server::handleMessage(const Message& msg) {
    switch(msg.getType()) {
        case MessageFactory::MSG_CONNECTION_REQ:
            this->handleMessage(static_cast<const MsgConnectionRequest&>(msg));
            break;
        case MessageFactory::MSG_DEBUG:
            this->handleMessage(static_cast<const MsgDebug&>(msg));
            break;
        default:
            LOG << "Bad message received (Unknown or invalid type: " << msg.getType() << ")\n";
            break;
    }
}

void Server::handleMessage(const MsgDebug& msg) {
    LOG << "Message received (MsgDebug)\n";
    LOG << "Debug content: " << msg.content();
}

void Server::handleMessage(const MsgConnectionRequest& msg) {
    LOG << "Message received (MsgConnectionRequest)\n";
    int id = _collabserver->createNewUser();
    Message* response = nullptr;
    response = MessageFactory::getInstance().newMessage(MessageFactory::MSG_CONNECTION_SUCCESS);
    static_cast<MsgConnectionSuccess*>(response)->setUserID(id);
    socket.sendMessage(*response);
}


} // End namespace


