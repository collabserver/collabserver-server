#pragma once

#include "messaging/IMessage.h"
#include "messaging/events/EventCreate.h"

#include <msgpack.hpp>


namespace collab {


class MessageCreate : public IMessage {
    private:
        /** Event that process this message. */
        EventCreate m_event;

    public:
        MessageCreate() = default;
        ~MessageCreate() = default;

    private:
        char* m_name;
        int a;
        int b;
        int c;

    public:
        void apply() override {
            this->m_event.receive(*this);
        }

        void serialize(char* stream) {
        }

        void deserialize(const char* stream) {
        }
};


} // End namespace
