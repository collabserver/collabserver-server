#pragma once

#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"
#include "event/debug/EventDebugDelete.h"


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

        int getID() const override {
            return static_cast<int>(MessageTypes::Create);
        }
};


} // End namespace
