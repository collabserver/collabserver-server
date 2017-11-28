#include "event/debug/EventDebugRead.h"
#include "message/debug/MessageDebugRead.h"

#include <elephant.h>


using namespace collab;


void EventDebugRead::run(Message& message) const {
    message = static_cast<MessageDebugRead&>(message);
    LOG_DEBUG(0, "EventDebugRead");
}

