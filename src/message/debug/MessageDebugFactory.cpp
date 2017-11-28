#include "message/debug/MessageDebugFactory.h"

#include "message/debug/MessageDebugCreate.h"
#include "message/debug/MessageDebugDelete.h"
#include "message/debug/MessageDebugRead.h"
#include "message/debug/MessageDebugUpdate.h"

using namespace collab;


Message* MessageDebugFactory::newMessage(const int type) const {
    switch(type) {
        case static_cast<int>(MessageDebugTypes::Create):
            return new MessageDebugCreate();

        case static_cast<int>(MessageDebugTypes::Delete):
            return new MessageDebugDelete();

        case static_cast<int>(MessageDebugTypes::Read):
            return new MessageDebugRead();

        case static_cast<int>(MessageDebugTypes::Update):
            return new MessageDebugUpdate();

        default:
            return nullptr;
    }
}

int MessageDebugFactory::getMessageTypeCounter() const {
    return static_cast<int>(MessageDebugTypes::CounterTypes);
}
