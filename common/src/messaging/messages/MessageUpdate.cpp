#include "messaging/messages/MessageUpdate.h"

using namespace collab;

void MessageUpdate::apply() {
    this->m_event.receive(*this);
}
