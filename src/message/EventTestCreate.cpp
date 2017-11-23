#include "message/EventTestCreate.h"

#include <logger/ElephantLogger.h>


using namespace collab;


void EventTestCreate::run(MessageTestCreate& message) {
    LOG_DEBUG(0, "EventTestCreate");
}
