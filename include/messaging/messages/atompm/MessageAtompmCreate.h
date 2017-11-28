#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/atompm/EventAtompmCreate.h"


namespace collab {


class MessageAtompmCreate : public IMessage {
    public:
        MessageAtompmCreate() {
            this->m_event = new EventAtompmCreate();
        }

        ~MessageAtompmCreate() = default;

    public:
        void apply() override {
            this->m_event->run(*this);
        }
};


} // End namespace
