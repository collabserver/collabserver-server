#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/debug/EventDebugRead.h"


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
};


} // End namespace
