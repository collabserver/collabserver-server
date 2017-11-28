#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class IMessage;


class EventDebugUpdate : public IMessageEvent {
    public:
        EventDebugUpdate() = default;
        ~EventDebugUpdate() = default;

    public:
        void run(IMessage& message) const override;
};


} // End namespace

