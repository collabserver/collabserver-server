#include "messaging/event/atompm/EventAtompmUpdate.h"

#include <elephant.h>


using namespace collab;


void EventAtompmUpdate::receive(MessageAtompmUpdate & message) const {
    LOG_DEBUG(0, "EventUpdate (AtomPM)");
}

