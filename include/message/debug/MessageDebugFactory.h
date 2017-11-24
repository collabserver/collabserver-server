#pragma once

#include "messaging/MessageAbsFactory.h"

namespace collab {

class Message;


/**
 * List all posible message for Debug message communication protocol.
 */
enum class MessageDebugTypes : int {
    Create,
    Update,

    // Internal use (TO KEEP LAST)
    CounterTypes
};


class MessageDebugFactory : public MessageAbsFactory {
    public:
        MessageDebugFactory() = default;
        ~MessageDebugFactory() = default;

    public:
        Message* newMessage(const int type) const override;
        int getMessageTypeCounter() const override;
};


} // End namespace
