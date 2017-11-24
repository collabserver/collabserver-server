#include "message/debug/MessageDebugFactory.h"
#include "message/debug/MessageDebugCreate.h"

using namespace collab;


Message* MessageDebugFactory::newMessage(const int type) const {
    switch(type) {
        case static_cast<int>(MessageDebugTypes::Create):
            return new MessageDebugCreate();
        default:
            return nullptr;
    }
}

int MessageDebugFactory::getMessageTypeCounter() const {
    return static_cast<int>(MessageDebugTypes::CounterTypes);
}
