#include "network/MessageReceiver.h"

#include "messaging/MessageFactory.h"
#include "messaging/IMessage.h"

#include <elephant.h>
#include <zmq.hpp>

using namespace collab;


MessageReceiver::MessageReceiver() {
    this->m_isRunning = false;
    this->m_messageFactory = new MessageFactory();
}

MessageReceiver::~MessageReceiver() {
    this->m_isRunning = false;
    delete this->m_messageFactory;
}

void MessageReceiver::start() {
    if(!this->m_isRunning) {
        this->m_isRunning = true;

        // TODO To move outside + config
        zmq::context_t context(1);
        zmq::socket_t socket(context, ZMQ_REP);
        socket.bind("tcp://*:5555");

        while(this->m_isRunning) {
            LOG_DEBUG(0, "Waiting for message...");
            zmq::message_t request;
            socket.recv(&request);

            this->processMessage(static_cast<char*>(request.data()), request.size());

            //TODO To update, for now, required by ZMQ_REP pattern.
            zmq::message_t reply(11);
            memcpy(reply.data(), "Acknowledge", 11);
            socket.send(reply);
        }
    }
}

void MessageReceiver::stop() {
    this->m_isRunning = false;
}

void MessageReceiver::processMessage(const char* msg, const size_t size) const {
    LOG_DEBUG(0, "Message received! Raw message (size %d): %s", size, msg);

    int msgType = static_cast<int>(msg[0]);
    LOG_DEBUG(0, "Recovered type: %d", msgType);

    IMessage *m = this->m_messageFactory->newMessage(msgType);
    if(m == nullptr) {
        LOG_DEBUG(0, "Unknown message type %d", msgType);
        return;
    }

    //m->deserialize(); // TODO
    m->apply();
    delete m; // Important since newMessage allocate with new
}
