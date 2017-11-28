#pragma once

#include "messaging/IMessage.h"
#include "messaging/MessageTypes.h"
#include "event/debug/EventDebugCreate.h"


namespace collab {


class MessageDebugCreate : public IMessage {
    public:
        MessageDebugCreate() {
            this->m_event = new EventDebugCreate();
        }

        ~MessageDebugCreate() = default;

    private:
        char* m_location;
        char* m_name;

    public:
        void apply() override {
            this->m_event->run(*this);
        }

        int getID() const override {
            return static_cast<int>(MessageTypes::Create);
        }
};


} // End namespace
