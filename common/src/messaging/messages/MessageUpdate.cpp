#include "messaging/messages/MessageUpdate.h"
#include <msgpack.hpp>

using namespace collab;

void MessageUpdate::apply() {
    this->m_event.receive(*this);
}

bool MessageUpdate::serialize(std::stringstream & buffer) const {
    // TODO
    return true;
}

bool MessageUpdate::unserialize(std::stringstream & stream) const {
    // TODO
    return true;
}
