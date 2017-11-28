#pragma once

#include "messaging/MessageAbsFactory.h"


namespace collab {

class Message;


/**
 * List all posible message for Atompm message communication protocol.
 *
 * \date Nov 2017
 */
enum class MessageAtompmTypes : int {
    Create = 1,
    Delete,
    Read,
    Update,


    // Internal use (TO KEEP LAST)
    CounterTypes
};


class MessageAtompmFactory : public MessageAbsFactory {
    public:
        MessageAtompmFactory() = default;
        ~MessageAtompmFactory() = default;

    public:
        Message* newMessage(const int type) const override;
        int getMessageTypeCounter() const override;
};


} // End namespace
