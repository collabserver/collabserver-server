#include "messaging/events/EventUpdate.h"

#include <elephantlogger/log.h>


using namespace collab;


void EventUpdate::receive(MessageUpdate & message) const {
    LOG_DEBUG(0, "EventUpdate (Server)");
}

