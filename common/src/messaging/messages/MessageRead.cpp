#include "messaging/messages/MessageRead.h"
#include <msgpack.hpp>

using namespace collab;

void MessageRead::apply() {
    this->m_event.receive(*this);
}

template<class Stream>
bool MessageRead::serialize(Stream & buffer) const {
    // TODO
    return true;
}

template<class Stream>
bool MessageRead::unserialize(Stream & stream) const {
    // TODO
    return true;
}
