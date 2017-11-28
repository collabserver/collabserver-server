#include "event/atompm/EventAtompmCreate.h"
#include "message/atompm/MessageAtompmCreate.h"

#include <elephant.h>


using namespace collab;


void EventAtompmCreate::run(IMessage& message) const {
    message = static_cast<MessageAtompmCreate&>(message);
    LOG_DEBUG(0, "EventCreate (AtomPM)");
}
