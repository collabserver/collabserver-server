#pragma once

#include "messaging/IMessage.h"
#include "messaging/events/EventRead.h"


namespace collab {


class MessageRead : public IMessage {
    private:
        /** Event that process this message. */
        EventRead m_event;

    public:
        MessageRead() = default;
        ~MessageRead() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
