#include "event/debug/EventDebugUpdate.h"
#include "message/debug/MessageDebugUpdate.h"

#include <elephant.h>


using namespace collab;


void EventDebugUpdate::run(IMessage& message) const {
    message = static_cast<MessageDebugUpdate&>(message);
    LOG_DEBUG(0, "EventUpdate (Debug)");
}

