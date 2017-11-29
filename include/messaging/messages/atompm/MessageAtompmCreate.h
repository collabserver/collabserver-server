#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/atompm/EventAtompmCreate.h"


namespace collab {


class MessageAtompmCreate : public IMessage {
    private:
        /** Event that process this message. */
        EventAtompmCreate m_event;

    public:
        MessageAtompmCreate() = default;
        ~MessageAtompmCreate() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
