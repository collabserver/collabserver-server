#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageDebugUpdate;


class EventDebugUpdate : public IMessageEvent<MessageDebugUpdate> {
    public:
        EventDebugUpdate() = default;
        ~EventDebugUpdate() = default;

    public:
        void receive(MessageDebugUpdate & message) const override;
};


} // End namespace

