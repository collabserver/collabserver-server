#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/debug/EventDebugUpdate.h"


namespace collab {


class MessageDebugUpdate : public IMessage {
    private:
        /** Event that process this message. */
        EventDebugUpdate m_event;

    public:
        MessageDebugUpdate() = default;
        ~MessageDebugUpdate() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
