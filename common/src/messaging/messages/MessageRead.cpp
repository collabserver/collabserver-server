#include "messaging/messages/MessageRead.h"
#include <msgpack.hpp>

using namespace collab;

void MessageRead::apply() {
    this->m_event.receive(*this);
}

bool MessageRead::serialize(std::stringstream & buffer) const {
    // TODO
    return true;
}

bool MessageRead::unserialize(std::stringstream & stream) {
    // TODO
    return true;
}

MessageTypes MessageRead::getType() const {
    return MessageTypes::Read;
}
