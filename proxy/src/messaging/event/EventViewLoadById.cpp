#include "messaging/event/EventViewLoadById.h"

#include <elephantlogger/log.h>


using namespace collab;


void EventViewLoadById::receive(MessageViewLoadById & message) const {
    LOG_DEBUG(0, "EventViewLoadById (Proxy)");
}

