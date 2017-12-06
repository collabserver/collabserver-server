#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageRead;


class EventRead : public IMessageEvent<MessageRead> {
    public:
        EventRead() = default;
        ~EventRead() = default;

    public:
        void receive(MessageRead & message) const override;
};


} // End namespace
