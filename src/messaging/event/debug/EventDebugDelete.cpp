#include "messaging/event/debug/EventDebugDelete.h"

#include <elephant.h>


using namespace collab;


void EventDebugDelete::receive(MessageDebugDelete & message) const {
    LOG_DEBUG(0, "EventDelete (Debug)");
}

