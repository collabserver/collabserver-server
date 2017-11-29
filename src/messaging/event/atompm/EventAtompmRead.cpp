#include "messaging/event/atompm/EventAtompmRead.h"

#include <elephant.h>


using namespace collab;


void EventAtompmRead::receive(MessageAtompmRead & message) const {
    LOG_DEBUG(0, "EventRead (AtomPM)");
}

