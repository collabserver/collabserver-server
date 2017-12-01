#pragma once

#include "messaging/IMessage.h"
#include "messaging/event/debug/EventDebugCreate.h"

#include <msgpack.hpp>


namespace collab {


class MessageDebugCreate : public IMessage {
    private:
        /** Event that process this message. */
        EventDebugCreate m_event;

    public:
        MessageDebugCreate() = default;
        ~MessageDebugCreate() = default;

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
