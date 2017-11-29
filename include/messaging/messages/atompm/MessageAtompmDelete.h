#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/atompm/EventAtompmDelete.h"


namespace collab {


class MessageAtompmDelete : public IMessage {
    private:
        /** Event that process this message. */
        EventAtompmDelete m_event;

    public:
        MessageAtompmDelete() = default;
        ~MessageAtompmDelete() = default;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }
};


} // End namespace
