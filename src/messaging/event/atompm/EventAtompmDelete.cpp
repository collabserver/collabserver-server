#include "messaging/event/atompm/EventAtompmDelete.h"
#include "messaging/messages/atompm/MessageAtompmDelete.h"

#include <elephant.h>


using namespace collab;


void EventAtompmDelete::run(IMessage& message) const {
    message = static_cast<MessageAtompmDelete&>(message);
    LOG_DEBUG(0, "EventDelete (AtomPM)");
}

