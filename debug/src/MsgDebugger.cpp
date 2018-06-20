#include "MsgDebugger.h"

#include <string>
#include <iostream>
#include <cassert>

#include "Terminal.h"
#include "InputHelper.h"

namespace collab {


class IMessage;


void MsgDebugger::run() {
    assert(this->_isRunning == false);
    if(this->_isRunning) {
        return;
    }
    this->_isRunning = true;

    ui::writeLine("----- Start Message Spawner Debugger -----");
    ui::writeLine("Enter 'stop' in message content to quit");

    ui::writeLine("Connecting to server...");
    _client.connect("localhost", 5555);

    while(this->_isRunning) {
        ui::writeLine(" ---------- Send new message ---------- ");
        ui::listAllMessages();

        ui::writeLine("Enter message type:");
        int msgType = readInt(stdin, 4);
        sendDummyMessage(msgType);
    }

    ui::writeLine("Disconnecting from server...");
    _client.disconnect();
}

void MsgDebugger::stop() {
    this->_isRunning = false;
}

void MsgDebugger::sendDummyMessage(const int type) const {
    // TODO
}


} // End namespace


