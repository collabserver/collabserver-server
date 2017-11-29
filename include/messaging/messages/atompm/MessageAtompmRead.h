#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/atompm/EventAtompmRead.h"


namespace collab {


class MessageAtompmRead : public IMessage {
    private:
        /** Event that process this message. */
        EventAtompmRead m_event;

    public:
        MessageAtompmRead() = default;
        ~MessageAtompmRead() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
