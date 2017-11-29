#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageDebugRead;


class EventDebugRead : public IMessageEvent<MessageDebugRead> {
    public:
        EventDebugRead() = default;
        ~EventDebugRead() = default;

    public:
        void receive(MessageDebugRead & message) const override;
};


} // End namespace

