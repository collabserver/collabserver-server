#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageCreate;


class EventCreate : public IMessageEvent<MessageCreate> {
    public:
        EventCreate() = default;
        ~EventCreate() = default;

    public:
        void receive(MessageCreate & message) const override;
};


} // End namespace
