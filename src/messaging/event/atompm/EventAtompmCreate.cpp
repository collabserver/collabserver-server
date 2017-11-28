#include "messaging/event/atompm/EventAtompmCreate.h"
#include "messaging/messages/atompm/MessageAtompmCreate.h"

#include <elephant.h>


using namespace collab;


void EventAtompmCreate::run(IMessage& message) const {
    message = static_cast<MessageAtompmCreate&>(message);
    LOG_DEBUG(0, "EventCreate (AtomPM)");
}
