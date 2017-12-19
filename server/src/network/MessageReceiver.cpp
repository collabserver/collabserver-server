#include "network/MessageReceiver.h"

#include "messaging/MessageFactory.h"
#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"

#include <elephantlogger/log.h>
#include <zmq.hpp>

using namespace collab;


MessageReceiver::MessageReceiver() :
    m_isRunning(false),
    m_messageFactory(MessageFactory::getInstance()) {
}

MessageReceiver::~MessageReceiver() {
    this->m_isRunning = false;
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
    const int msgType = static_cast<int>(msg[0]);
    const char* msgData = msg+1;
    const size_t msgSize = size-1;

    LOG_DEBUG(0, "Message received! Type: %d, Size: %d, Raw content: %s", msgType, msgSize, msgData);

    IMessage *m = this->m_messageFactory.newMessage(static_cast<MessageTypes>(msgType));
    if(m == nullptr) {
        LOG_DEBUG(0, "Unknown message type %d", msgType);
        return;
    }

    std::stringstream stream;
    stream.str(std::string(msgData, msgSize));
    m->unserialize(stream);
    m->apply();
    delete m; // Important since newMessage allocate with new
}
