#include "messaging/event/debug/EventDebugCreate.h"
#include "messaging/messages/debug/MessageDebugCreate.h"

#include <elephant.h>


using namespace collab;


void EventDebugCreate::run(IMessage& message) const {
    message = static_cast<MessageDebugCreate&>(message);
    LOG_DEBUG(0, "EventCreate (Debug)");
}
