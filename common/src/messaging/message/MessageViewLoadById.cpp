#include "messaging/message/MessageViewLoadById.h"

#include <msgpack.hpp>

using namespace collab;

void MessageViewLoadById::apply() {
    //this->m_event->receive(*this); TODO
}

bool MessageViewLoadById::serialize(std::stringstream & buffer) const {
    // TODO
    return true;
}

bool MessageViewLoadById::unserialize(std::stringstream & stream) {
    // TODO
    return true;
}

MessageTypes MessageViewLoadById::getType() const {
    return MessageTypes::VIEW_LOAD_BY_ID;
}
