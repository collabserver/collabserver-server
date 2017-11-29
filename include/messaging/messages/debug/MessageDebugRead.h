#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/debug/EventDebugRead.h"


namespace collab {


class MessageDebugRead : public IMessage {
    private:
        /** Event that process this message. */
        EventDebugRead m_event;

    public:
        MessageDebugRead() = default;
        ~MessageDebugRead() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
