#include "messaging/messages/MessageDelete.h"

using namespace collab;

void MessageDelete::apply() {
    this->m_event.receive(*this);
}
