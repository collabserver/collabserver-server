#include "event/debug/EventDebugDelete.h"
#include "message/debug/MessageDebugDelete.h"

#include <elephant.h>


using namespace collab;


void EventDebugDelete::run(Message& message) const {
    message = static_cast<MessageDebugDelete&>(message);
    LOG_DEBUG(0, "EventDebugDelete");
}

