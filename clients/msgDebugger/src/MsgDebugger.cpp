#include "MsgDebugger.h"

#include "terminal.h"
#include "inputHelper.h"

#include "network/MessageHelper.h"
#include "messaging/MessageFactory.h"
#include "messaging/MessageTypes.h"

#include <string>
#include <iostream>
#include <cassert>


using namespace collab;
class IMessage;


void MsgDebugger::run() {
    this->m_isRunning = true;

    ui::writeLine("----- Start Message Spawner Debugger -----");
    ui::writeLine("Enter 'stop' in message content to quit");

    ui::writeLine("Connecting to server...");
    this->m_proxy.connect("localhost", 5555);

    while(this->m_isRunning) {
        ui::writeLine(" ---------- Send new message ---------- ");
        ui::listAllMessages();

        ui::writeLine("Enter message type:");
        int msgType = readInt(stdin, 4);
        sendDummyMessage(msgType);
    }

    ui::writeLine("Disconnecting from server...");
    this->m_proxy.disconnect();
}

void MsgDebugger::stop() {
    this->m_isRunning = false;
}

void MsgDebugger::sendDummyMessage(const int type) const {
    const MessageTypes msgType = static_cast<MessageTypes>(type);
    const int eltID = 1;

    switch(msgType) {
        case MessageTypes::Create:
            this->m_proxy.createElt(eltID, "Dummy create");
            break;
        case MessageTypes::Read:
            this->m_proxy.readElt(eltID, "Dummy read");
            break;
        case MessageTypes::Update:
            this->m_proxy.updateElt(eltID, "Dummy update");
            break;
        case MessageTypes::Delete:
            this->m_proxy.deleteElt(eltID);
            break;
        default:
            ui::writeLine("Unable to send message: invalid type");
            break;
    }
}


