#include "message/atompm/MessageAtompmFactory.h"
#include "messaging/MessageTypes.h"

#include "message/atompm/MessageAtompmCreate.h"
#include "message/atompm/MessageAtompmDelete.h"
#include "message/atompm/MessageAtompmRead.h"
#include "message/atompm/MessageAtompmUpdate.h"

using namespace collab;


IMessage* MessageAtompmFactory::newMessage(const int type) const {
    // Switch-case is actually flexible and fast for this use-case.
    switch(type) {
        case static_cast<int>(MessageTypes::Create):
            return new MessageAtompmCreate();

        case static_cast<int>(MessageTypes::Delete):
            return new MessageAtompmDelete();

        case static_cast<int>(MessageTypes::Read):
            return new MessageAtompmRead();

        case static_cast<int>(MessageTypes::Update):
            return new MessageAtompmUpdate();

        default:
            return nullptr;
    }
}
