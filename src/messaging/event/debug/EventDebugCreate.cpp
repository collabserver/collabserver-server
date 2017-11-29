#include "messaging/event/debug/EventDebugCreate.h"

#include <elephant.h>


using namespace collab;


void EventDebugCreate::receive(MessageDebugCreate & message) const {
    LOG_DEBUG(0, "EventCreate (Debug)");
}
