#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageAtompmRead;


class EventAtompmRead : public IMessageEvent<MessageAtompmRead> {
    public:
        EventAtompmRead() = default;
        ~EventAtompmRead() = default;

    public:
        void receive(MessageAtompmRead & message) const override;
};


} // End namespace
