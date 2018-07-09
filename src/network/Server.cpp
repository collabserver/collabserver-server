#include "collabserver/network/Server.h"

#include <zmq.hpp>

#include "collabcommon/network/Network.h"
#include "collabcommon/network/ZMQSocket.h"
#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/messaging/IMessage.h"


namespace collab {


class IMessage;


void Server::start() {
    if(_isRunning) {
        return;
    }
    _isRunning = true;

    ZMQSocketConfig config = {
        ZMQ_REP,
        network::g_context,
        &(MessageFactory::getInstance())
    };

    ZMQSocket socket(config);
    socket.bind("*", 1234);

    while(_isRunning) {
        std::unique_ptr<IMessage> msg = socket.receiveMessage();

        // TODO: Process
        // TODO: Send response (Create debug tmp message)
        //socket.sendMessage(msg);
    }
}

void Server::stop() {
    this->_isRunning = false;
}


} // End namespace


