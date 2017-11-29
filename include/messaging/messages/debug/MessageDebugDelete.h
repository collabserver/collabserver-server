#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/debug/EventDebugDelete.h"


namespace collab {


class MessageDebugDelete : public IMessage {
    private:
        /** Event that process this message. */
        EventDebugDelete m_event;

    public:
        MessageDebugDelete() = default;
        ~MessageDebugDelete() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
