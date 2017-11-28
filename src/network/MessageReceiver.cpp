#include "network/MessageReceiver.h"
#include "messaging/MessageRouter.h"

#include <elephant.h>
#include <zmq.hpp>

using namespace collab;


MessageReceiver::MessageReceiver(MessageRouter& router)
    : m_messageRouter(router) {
    this->m_isRunning = false;
}

MessageReceiver::~MessageReceiver() {
    this->m_isRunning = false;
}

void MessageReceiver::start() {
    if(!this->m_isRunning) {
        this->m_isRunning = true;
        zmq::context_t context(1);
        zmq::socket_t socket(context, ZMQ_REP);
        socket.bind("tcp://*:5555");

        while(this->m_isRunning) {
            LOG_DEBUG(0, "Waiting for message...");
            zmq::message_t request;
            socket.recv(&request);
            LOG_DEBUG(0, "Message received");

            this->m_messageRouter.processMessage(
                    static_cast<char*>(request.data()), request.size());

            //TODO To update, for now, required by ZMQ_REP pattern.
            zmq::message_t reply(11);
            memcpy(reply.data(), "Acknowledge", 11);
            socket.send(reply);
            LOG_DEBUG(0, "Replay (acknowledge) sent");
        }
    }
}

void MessageReceiver::stop() {
    this->m_isRunning = false;
}
