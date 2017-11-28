#include "event/atompm/EventAtompmUpdate.h"
#include "message/atompm/MessageAtompmUpdate.h"

#include <elephant.h>


using namespace collab;


void EventAtompmUpdate::run(Message& message) const {
    message = static_cast<MessageAtompmUpdate&>(message);
    LOG_DEBUG(0, "EventAtompmUpdate");
}

