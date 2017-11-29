#include "messaging/event/atompm/EventAtompmDelete.h"

#include <elephant.h>


using namespace collab;


void EventAtompmDelete::receive(MessageAtompmDelete & message) const {
    LOG_DEBUG(0, "EventDelete (AtomPM)");
}

