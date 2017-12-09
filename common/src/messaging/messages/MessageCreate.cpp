#include "messaging/messages/MessageCreate.h"
#include <msgpack.hpp>

using namespace collab;


void MessageCreate::apply() {
    this->m_event.receive(*this);
}

bool MessageCreate::serialize(std::stringstream & buffer) const {
    msgpack::pack(buffer, this->m_a);
    msgpack::pack(buffer, this->m_b);
    msgpack::pack(buffer, this->m_c);
    return true;
}

#include <elephantlogger/log.h>
bool MessageCreate::unserialize(std::stringstream & buffer) {
    const char* data    = buffer.str().data();
    const size_t size   = buffer.str().size();
    std::size_t off     = 0;

    msgpack::unpacked result;

    // m_a
    msgpack::unpack(result, data, size, off);
    result.get().convert(this->m_a);
    LOG_DEBUG(0, "VALUE: %d", this->m_a);

    // m_b
    msgpack::unpack(result, data, size, off);
    this->m_b = result.get().as<int>();
    LOG_DEBUG(0, "VALUE: %d", this->m_b);

    // m_c
    msgpack::unpack(result, data, size, off);
    result.get().convert(this->m_c);
    LOG_DEBUG(0, "VALUE: %d", this->m_c);
    return true;
}
