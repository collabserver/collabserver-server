#pragma once

#include "messaging/MessageAbsFactory.h"


namespace collab {


class MessageAtompmFactory : public MessageAbsFactory {
    public:
        MessageAtompmFactory() = default;
        ~MessageAtompmFactory() = default;

    public:
        IMessage* newMessage(const int type) const override;
};


} // End namespace
