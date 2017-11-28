#include "message/atompm/MessageAtompmFactory.h"

#include "message/atompm/MessageAtompmCreate.h"
#include "message/atompm/MessageAtompmDelete.h"
#include "message/atompm/MessageAtompmRead.h"
#include "message/atompm/MessageAtompmUpdate.h"

using namespace collab;


Message* MessageAtompmFactory::newMessage(const int type) const {
    switch(type) {
        case static_cast<int>(MessageAtompmTypes::Create):
            return new MessageAtompmCreate();

        case static_cast<int>(MessageAtompmTypes::Delete):
            return new MessageAtompmDelete();

        case static_cast<int>(MessageAtompmTypes::Read):
            return new MessageAtompmRead();

        case static_cast<int>(MessageAtompmTypes::Update):
            return new MessageAtompmUpdate();

        default:
            return nullptr;
    }
}

int MessageAtompmFactory::getMessageTypeCounter() const {
    return static_cast<int>(MessageAtompmTypes::CounterTypes);
}

