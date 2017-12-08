#include "messaging/events/EventRead.h"

#include <elephantlogger/log.h>


using namespace collab;


void EventRead::receive(MessageRead & message) const {
    LOG_DEBUG(0, "EventRead (Server)");
}

