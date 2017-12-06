#include "messaging/events/EventCreate.h"

#include <elephant.h>


using namespace collab;


void EventCreate::receive(MessageCreate & message) const {
    LOG_DEBUG(0, "EventCreate (Server)");
}
