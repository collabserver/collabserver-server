#pragma once

#include "messaging/IMessage.h"
#include "messaging/events/EventUpdate.h"


namespace collab {


class MessageUpdate : public IMessage {
    private:
        /** Event that process this message. */
        EventUpdate m_event;

    public:
        MessageUpdate() = default;
        ~MessageUpdate() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
