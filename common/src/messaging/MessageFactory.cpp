#include "messaging/MessageFactory.h"
#include "messaging/MessageTypes.h"

#include "messaging/messages/MessageCreate.h"
#include "messaging/messages/MessageDelete.h"
#include "messaging/messages/MessageRead.h"
#include "messaging/messages/MessageUpdate.h"


using namespace collab;


IMessage* MessageFactory::newMessage(const int type) const {
    // Switch-case is actually flexible and fast for this use-case.
    switch(type) {
        case static_cast<int>(MessageTypes::Create):
            return new MessageCreate();

        case static_cast<int>(MessageTypes::Delete):
            return new MessageDelete();

        case static_cast<int>(MessageTypes::Read):
            return new MessageRead();

        case static_cast<int>(MessageTypes::Update):
            return new MessageUpdate();

        default:
            return nullptr;
    }
}
