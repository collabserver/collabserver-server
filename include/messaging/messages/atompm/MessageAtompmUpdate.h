#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/atompm/EventAtompmUpdate.h"


namespace collab {


class MessageAtompmUpdate : public IMessage {
    private:
        /** Event that process this message. */
        EventAtompmUpdate m_event;

    public:
        MessageAtompmUpdate() = default;
        ~MessageAtompmUpdate() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
