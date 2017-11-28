#pragma once

#include "messaging/MessageAbsFactory.h"


namespace collab {


class MessageDebugFactory : public MessageAbsFactory {
    public:
        MessageDebugFactory() = default;
        ~MessageDebugFactory() = default;

    public:
        IMessage* newMessage(const int type) const override;
};


} // End namespace
