#include "messaging/event/atompm/EventAtompmUpdate.h"
#include "messaging/messages/atompm/MessageAtompmUpdate.h"

#include <elephant.h>


using namespace collab;


void EventAtompmUpdate::run(IMessage& message) const {
    message = static_cast<MessageAtompmUpdate&>(message);
    LOG_DEBUG(0, "EventUpdate (AtomPM)");
}

