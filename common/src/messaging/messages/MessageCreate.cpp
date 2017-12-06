#include "messaging/messages/MessageCreate.h"

using namespace collab;


void MessageCreate::apply() {
    this->m_event.receive(*this);
}
