#include "messaging/event/atompm/EventAtompmCreate.h"

#include <elephant.h>


using namespace collab;


void EventAtompmCreate::receive(MessageAtompmCreate & message) const {
    LOG_DEBUG(0, "EventCreate (AtomPM)");
}
