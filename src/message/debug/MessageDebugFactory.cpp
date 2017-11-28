#include "message/debug/MessageDebugFactory.h"
#include "messaging/MessageTypes.h"

#include "message/debug/MessageDebugCreate.h"
#include "message/debug/MessageDebugDelete.h"
#include "message/debug/MessageDebugRead.h"
#include "message/debug/MessageDebugUpdate.h"

using namespace collab;


IMessage* MessageDebugFactory::newMessage(const int type) const {
    // Switch-case is actually flexible and fast for this use-case.
    switch(type) {
        case static_cast<int>(MessageTypes::Create):
            return new MessageDebugCreate();

        case static_cast<int>(MessageTypes::Delete):
            return new MessageDebugDelete();

        case static_cast<int>(MessageTypes::Read):
            return new MessageDebugRead();

        case static_cast<int>(MessageTypes::Update):
            return new MessageDebugUpdate();

        default:
            return nullptr;
    }
}
