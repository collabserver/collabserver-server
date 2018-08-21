#include "collabserver/network/Server.h"

#include <cassert>
#include <zmq.hpp>

#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/network/ZMQSocket.h"
#include "collabcommon/utils/Log.h"

namespace collab {


Server::Server(const ServerConfig& config) {
    _address    = config.address;
    _port       = config.port;
}

Server::~Server() {
    this->stop();
}

void Server::start() {
    assert(_isRunning == false);
    if(_isRunning) {
        return;
    }
    _isRunning = true;
    LOG << "Starting network server\n";

    ZMQSocketConfig config = {
        ZMQ_REP,
        &g_context,
        &(MessageFactory::getInstance())
    };

    ZMQSocket socket(config);
    LOG << "Binding socket: (" << _address << ", " << _port << ")\n";
    socket.bind(_address.c_str(), _port);
    LOG << "Socket successfully binded\n";

    while(_isRunning) {
        LOG << "Waiting for any message\n";
        std::unique_ptr<Message> msg = socket.receiveMessage();
        this->handleMessage(*msg);
        socket.sendMessage(*msg); // TODO for now, simply echo the msg
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
    // TODO
}

void Server::handleMessage(const MsgConnectionRequest& msg) {
    LOG << "Message received (MsgConnectionRequest)\n";
    // TODO
}


} // End namespace


