#include "messaging/messages/MessageUpdate.h"
#include <msgpack.hpp>

using namespace collab;

void MessageUpdate::apply() {
    this->m_event.receive(*this);
}

template<class Stream>
bool MessageUpdate::serialize(Stream & buffer) const {
    // TODO
    return true;
}

template<class Stream>
bool MessageUpdate::unserialize(Stream & stream) const {
    // TODO
    return true;
}
