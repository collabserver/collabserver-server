#include "messaging/event/debug/EventDebugDelete.h"
#include "messaging/messages/debug/MessageDebugDelete.h"

#include <elephant.h>


using namespace collab;


void EventDebugDelete::run(IMessage& message) const {
    message = static_cast<MessageDebugDelete&>(message);
    LOG_DEBUG(0, "EventDelete (Debug)");
}

