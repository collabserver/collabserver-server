#include "messaging/messages/MessageDelete.h"
#include <msgpack.hpp>

using namespace collab;

void MessageDelete::apply() {
    this->m_event.receive(*this);
}

template<class Stream>
bool MessageDelete::serialize(Stream & buffer) const {
    // TODO
    return true;
}

template<class Stream>
bool MessageDelete::unserialize(Stream & stream) const {
    // TODO
    return true;
}
