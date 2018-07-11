#include "collabserver/network/Server.h"

#include <cassert>
#include <zmq.hpp>

#include "collabcommon/utils/Log.h"
#include "collabcommon/network/Network.h"
#include "collabcommon/network/ZMQSocket.h"
#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/messaging/Message.h"


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
        &network::g_context,
        &(MessageFactory::getInstance())
    };

    LOG << "Connecting socket: (" << _address << ", " << _port << ")\n";
    ZMQSocket socket(config);
    socket.bind(_address.c_str(), _port);

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


