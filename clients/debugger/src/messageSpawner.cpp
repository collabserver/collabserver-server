#include "messageSpawner.h"
#include "terminal.h"
#include "inputHelper.h"

#include "messaging/IMessage.h"
#include "messaging/MessageFactory.h"

#include <stdlib.h> // atoi
#include <string.h> // memcpy

#include <elephantlogger/log.h>
#include <sstream>  // std::stringstream
#include <iostream> // std::cin
#include <zmq.hpp>


static zmq::context_t context(1);
static zmq::socket_t socket(context, ZMQ_REQ);


static int getMsgType() {
    ui::writeLine("Enter message type:");
    char buffer[4];
    readFromStream(stdin, buffer, 3);
    int coco = atoi(buffer);
    return (coco >= 0 && coco <= 255) ? coco : 0;
}

void getRawMsgContent(std::stringstream& buffer) {
    ui::writeLine("Enter message content:");
    std::string inputStr;
    std::getline(std::cin, inputStr);
}

static size_t getStreamSize(std::stringstream & stream) {
    stream.seekg(0, std::ios::end);
    const size_t size = stream.tellg();
    stream.seekg(0);
    return size;
}

void runSpawner() {
    bool isRunning = true;
    ui::writeLine("----- Start Message Spawner Debugger -----");
    ui::writeLine("Enter 'stop' in message content to quit");

    ui::writeLine("Connecting to server...");
    socket.connect("tcp://localhost:5555");

    while(isRunning) {
        ui::writeLine(" ---------- Send new message ---------- ");
        ui::listAllMessages();

        char msgType = getMsgType();
        if(sendDummyMessage(msgType) == true){
            zmq::message_t reply;
            socket.recv(&reply);
            ui::writeLine("Acknowledgement received");
        }

    }
}

bool sendDummyMessage(const int type) {
    collab::IMessage* msg = collab::MessageFactory::getInstance().newMessage(type);
    if(msg == nullptr) {
        ui::writeLine("Message type (%d) doesn't exists", type);
        return false;
    }

    // TODO fill message according to type.

    std::stringstream buffer;
    //msg->serialize(buffer);
    size_t msgSize = getStreamSize(buffer);

    // ZMQ Message
    zmq::message_t request(msgSize + 1); // +1 for the msg type elt

    char* ptrStart = static_cast<char*>(request.data()) + 1;
    memcpy(request.data(), &type, 1);
    memcpy(ptrStart, buffer.str().c_str(), msgSize); 
    socket.send(request);
    return true;
}

