#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/atompm/EventAtompmDelete.h"


namespace collab {


class MessageAtompmDelete : public IMessage {
    public:
        MessageAtompmDelete() {
            this->m_event = new EventAtompmDelete();
        }

        ~MessageAtompmDelete() = default;

    public:
        void apply() override {
            this->m_event->run(*this);
        }
};


} // End namespace
