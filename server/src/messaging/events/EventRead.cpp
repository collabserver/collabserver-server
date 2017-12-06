#include "messaging/events/EventRead.h"

#include <elephant.h>


using namespace collab;


void EventRead::receive(MessageRead & message) const {
    LOG_DEBUG(0, "EventRead (Server)");
}

