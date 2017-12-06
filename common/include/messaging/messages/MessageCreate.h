#pragma once

#include "messaging/IMessage.h"
#include "messaging/events/EventCreate.h"

#include <msgpack.hpp>


namespace collab {


/**
 * Implements IMessage for Create operation.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
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
        void apply() override;

        // TODO
        void serialize(char* stream) {
        }
        void deserialize(const char* stream) {
        }
};


} // End namespace
