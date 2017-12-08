#include "messaging/messages/MessageDelete.h"
#include <msgpack.hpp>

using namespace collab;

void MessageDelete::apply() {
    this->m_event.receive(*this);
}

bool MessageDelete::serialize(std::stringstream & buffer) const {
    // TODO
    return true;
}

bool MessageDelete::unserialize(std::stringstream & stream) const {
    // TODO
    return true;
}
