#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/atompm/EventAtompmUpdate.h"


namespace collab {


class MessageAtompmUpdate : public IMessage {
    public:
        MessageAtompmUpdate() {
            this->m_event = new EventAtompmUpdate();
        }

        ~MessageAtompmUpdate() = default;

    public:
        void apply() override {
            this->m_event->run(*this);
        }
};


} // End namespace
