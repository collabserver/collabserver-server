#include "messaging/message/view/response/LoadById.h"

#include <msgpack.hpp>


using namespace collab;
namespace msg = message::view::response;


void msg::LoadById::apply() {
    // TODO
    //this->m_event->receive(*this);
}

bool msg::LoadById::serialize(std::stringstream & buffer) const {
    // TODO
    return true;
}

bool msg::LoadById::unserialize(std::stringstream & stream) {
    // TODO
    return true;
}

MessageTypes msg::LoadById::getType() const {
    return MessageTypes::VIEW_RESPONSE_LOAD_BY_ID;
}

