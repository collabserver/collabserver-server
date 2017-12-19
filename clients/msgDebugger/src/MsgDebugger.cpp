#include "MsgDebugger.h"

#include "terminal.h"
#include "inputHelper.h"
#include "network/MessageHelper.h"

#include <string>
#include <iostream>
#include <cassert>


using namespace collab;


void MsgDebugger::run() {
    this->m_isRunning = true;

    ui::writeLine("----- Start Message Spawner Debugger -----");
    ui::writeLine("Enter 'stop' in message content to quit");

    //ui::writeLine("Connecting to server...");

    while(this->m_isRunning) {
        ui::writeLine(" ---------- Send new message ---------- ");
        ui::listAllMessages();

        ui::writeLine("Enter message type:");
        int coco = readInt(stdin, 4);
        char msgType = (coco >= 0 && coco <= 255) ? coco : 0;

        /*
        if(sendDummyMessage(msgType) == true){
            zmq::message_t reply;
            socket.recv(&reply);
            ui::writeLine("Acknowledgement received");
        }
        */
    }
}

void MsgDebugger::stop() {
    this->m_isRunning = false;
}
