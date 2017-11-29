#include "messaging/event/debug/EventDebugUpdate.h"

#include <elephant.h>


using namespace collab;


void EventDebugUpdate::receive(MessageDebugUpdate& message) const {
    LOG_DEBUG(0, "EventUpdate (Debug)");
}

