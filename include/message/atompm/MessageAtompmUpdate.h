#pragma once

#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"
#include "event/atompm/EventAtompmUpdate.h"


namespace collab {


class MessageAtompmUpdate : public IMessage {
    public:
        MessageAtompmUpdate() {
            this->m_event = new EventAtompmUpdate();
        }

        ~MessageAtompmUpdate() = default;

    public:
        void apply() override {
            this->m_event->run(*this);
        }

        int getID() const override {
            return static_cast<int>(MessageTypes::Create);
        }
};


} // End namespace
