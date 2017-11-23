#include "message/EventTestCreate.h"

#include <logger/elephant.h>


using namespace collab;


void EventTestCreate::run(Message& message) const {
    message = static_cast<MessageTestCreate&>(message);
    LOG_DEBUG(0, "EventTestCreate");
}
