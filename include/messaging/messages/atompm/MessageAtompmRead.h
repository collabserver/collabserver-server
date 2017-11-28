#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/atompm/EventAtompmRead.h"


namespace collab {


class MessageAtompmRead : public IMessage {
    public:
        MessageAtompmRead() {
            this->m_event = new EventAtompmRead();
        }

        ~MessageAtompmRead() = default;

    public:
        void apply() override {
            this->m_event->run(*this);
        }
};


} // End namespace
