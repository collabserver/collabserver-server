#include "messaging/event/debug/EventDebugRead.h"

#include <elephant.h>


using namespace collab;


void EventDebugRead::receive(MessageDebugRead & message) const {
    LOG_DEBUG(0, "EventRead (Debug)");
}

