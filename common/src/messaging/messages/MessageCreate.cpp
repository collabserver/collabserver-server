#include "messaging/messages/MessageCreate.h"
#include <msgpack.hpp>

using namespace collab;


void MessageCreate::apply() {
    this->m_event.receive(*this);
}

bool MessageCreate::serialize(std::stringstream & buffer) const {
    msgpack::pack(buffer, 42);  // int a
    msgpack::pack(buffer, 20);  // int b
    msgpack::pack(buffer, true);// int c
    return true;
}

bool MessageCreate::unserialize(std::stringstream & stream) const {
    return true;
}
