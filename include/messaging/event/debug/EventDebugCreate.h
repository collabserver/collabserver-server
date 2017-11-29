#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageDebugCreate;


class EventDebugCreate : public IMessageEvent<MessageDebugCreate> {
    public:
        EventDebugCreate() = default;
        ~EventDebugCreate() = default;

    public:
        void receive(MessageDebugCreate & message) const override;
};


} // End namespace
