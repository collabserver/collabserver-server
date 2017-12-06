#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageDelete;


class EventDelete : public IMessageEvent<MessageDelete> {
    public:
        EventDelete() = default;
        ~EventDelete() = default;

    public:
        void receive(MessageDelete & message) const override;
};


} // End namespace
