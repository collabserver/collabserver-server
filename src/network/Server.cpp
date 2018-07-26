#include "collabserver/network/Server.h"

#include <cassert>
#include <zmq.hpp>

#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/messaging/Message.h"
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
    bool success = socket.bind(_address.c_str(), _port);
    if(!success) {
        LOG << "Unable to bind socket\n";
        return;
    }
    LOG << "Socket successfully binded\n";

    while(_isRunning) {
        LOG << "Waiting for message\n";
        std::unique_ptr<Message> msg = socket.receiveMessage();
        LOG << "Message received\n";

        // TODO: Process msg
        socket.sendMessage(*msg); // TODO for now, simply echo the msg
    }

    socket.unbind();
}

void Server::stop() {
    this->_isRunning = false;
}


} // End namespace


