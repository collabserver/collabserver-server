#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/debug/EventDebugDelete.h"


namespace collab {


class MessageDebugDelete : public IMessage {
    public:
        MessageDebugDelete() {
            this->m_event = new EventDebugDelete();
        }

        ~MessageDebugDelete() = default;

    public:
        void apply() override {
            this->m_event->run(*this);
        }
};


} // End namespace
