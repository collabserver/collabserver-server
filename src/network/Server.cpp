#include "network/Server.h"

#include <logger/elephant.h>
#include <zmq.hpp>

using namespace collab;


Server::Server() {
    this->isRunning = false;
}

Server::~Server() {
    this->isRunning = false;
}

void Server::start() {
    if(!this->isRunning) {
        this->isRunning = true;
        zmq::context_t context(1);
        zmq::socket_t socket(context, ZMQ_REP);
        socket.bind("tcp://*:5555");

        while(this->isRunning) {
            LOG_DEBUG(0, "Wait for message...");
            zmq::message_t request;
            socket.recv(&request);
            //LOG_DEBUG(0, "Message message received:");
            //std::string msg(static_cast<char*>(request.data()), request.size());
            //LOG_DEBUG(0, msg.c_str());
            //LOG_DEBUG(0, static_cast<char*>(request.data()));

            this->router.processMessage(static_cast<char*>(request.data()), request.size());

            //TODO
            zmq::message_t reply(11);
            memcpy(reply.data(), "Acknowledge", 11);
            socket.send(reply);
        }
    }
}

void Server::stop() {
    this->isRunning = false;
}
