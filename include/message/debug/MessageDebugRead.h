#pragma once

#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"
#include "event/debug/EventDebugRead.h"


namespace collab {


class MessageDebugRead : public IMessage {
    public:
        MessageDebugRead() {
            this->m_event = new EventDebugRead();
        }

        ~MessageDebugRead() = default;

    public:
        void apply() override {
            this->m_event->run(*this);
        }

        int getID() const override {
            return static_cast<int>(MessageTypes::Create);
        }
};


} // End namespace
