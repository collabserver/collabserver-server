#pragma once

#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"
#include "event/atompm/EventAtompmCreate.h"


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

        int getID() const override {
            return static_cast<int>(MessageTypes::Create);
        }
};


} // End namespace
