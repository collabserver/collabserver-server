#pragma once

#include "messaging/IMessage.h"
#include "messaging/events/EventDelete.h"


namespace collab {


class MessageDelete : public IMessage {
    private:
        /** Event that process this message. */
        EventDelete m_event;

    public:
        MessageDelete() = default;
        ~MessageDelete() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
