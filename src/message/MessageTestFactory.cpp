#include "message/MessageTestFactory.h"
#include "message/MessageTestCreate.h"

using namespace collab;


Message* MessageTestFactory::newMessage(const int type) const {
    switch(type) {
        case static_cast<int>(MessageTestTypes::Create):
            return new MessageTestCreate();
        default:
            return nullptr;
    }
}

int MessageTestFactory::getMessageTypeCounter() const {
    return static_cast<int>(MessageTestTypes::CounterTypes);
}
