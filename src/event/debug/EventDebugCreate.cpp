#include "event/debug/EventDebugCreate.h"
#include "message/debug/MessageDebugCreate.h"

#include <elephant.h>


using namespace collab;


void EventDebugCreate::run(Message& message) const {
    message = static_cast<MessageDebugCreate&>(message);
    LOG_DEBUG(0, "EventDebugCreate");
}
