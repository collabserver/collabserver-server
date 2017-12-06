#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageUpdate;

class EventUpdate : public IMessageEvent<MessageUpdate> {
    public:
        EventUpdate() = default;
        ~EventUpdate() = default;

    public:
        void receive(MessageUpdate & message) const override;
};


} // End namespace
