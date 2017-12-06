#include "messaging/messages/MessageRead.h"

using namespace collab;

void MessageRead::apply() {
    this->m_event.receive(*this);
}
