#pragma once

#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"
#include "event/atompm/EventAtompmDelete.h"


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

        int getID() const override {
            return static_cast<int>(MessageTypes::Create);
        }
};


} // End namespace
