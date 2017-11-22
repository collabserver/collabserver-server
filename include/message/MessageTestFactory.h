#pragma once

#include "AbsMessageFactory.h"

namespace collab {


enum class MessageTestTypes : int {
    Create,
    Update,

    // Internal use (TO KEEP LAST)
    CounterTypes
};


class MessageTestFactory : public AbsMessageFactory {
    public:
        MessageTestFactory() = default;
        ~MessageTestFactory() = default;

    public:
        Message* newMessage(const int type) const override;
        int getMessageTypeCounter() const override;
};


} // End namespace
