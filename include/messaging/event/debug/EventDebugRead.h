#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class IMessage;


class EventDebugRead : public IMessageEvent {
    public:
        EventDebugRead() = default;
        ~EventDebugRead() = default;

    public:
        void run(IMessage& message) const override;
};


} // End namespace

