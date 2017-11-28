#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class IMessage;


class EventAtompmRead : public IMessageEvent {
    public:
        EventAtompmRead() = default;
        ~EventAtompmRead() = default;

    public:
        void run(IMessage& message) const override;
};


} // End namespace
