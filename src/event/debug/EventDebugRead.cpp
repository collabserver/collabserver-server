#include "event/debug/EventDebugRead.h"
#include "message/debug/MessageDebugRead.h"

#include <elephant.h>


using namespace collab;


void EventDebugRead::run(IMessage& message) const {
    message = static_cast<MessageDebugRead&>(message);
    LOG_DEBUG(0, "EventRead (Debug)");
}

