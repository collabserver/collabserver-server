#include "messaging/messages/MessageCreate.h"
#include <msgpack.hpp>

using namespace collab;


void MessageCreate::apply() {
    this->m_event.receive(*this);
}

template<class Stream>
bool MessageCreate::serialize(Stream & buffer) const {
    msgpack::pack(buffer, 42);  // int a
    msgpack::pack(buffer, 20);  // int b
    msgpack::pack(buffer, true);// int c
    return true;
}

template<class Stream>
bool MessageCreate::unserialize(Stream & stream) const {
    return true;
}
