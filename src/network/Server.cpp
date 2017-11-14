#include "network/Server.h"

#include <zmq.hpp>
#include <iostream>

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
            zmq::message_t messageReceived;
            socket.recv(&messageReceived);
            std::cout << "Message received" << std::endl;
            // TODO
        }
    }
}

void Server::stop() {
    this->isRunning = false;
}
