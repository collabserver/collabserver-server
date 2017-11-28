#include "event/atompm/EventAtompmDelete.h"
#include "message/atompm/MessageAtompmDelete.h"

#include <elephant.h>


using namespace collab;


void EventAtompmDelete::run(Message& message) const {
    message = static_cast<MessageAtompmDelete&>(message);
    LOG_DEBUG(0, "EventAtompmDelete");
}

