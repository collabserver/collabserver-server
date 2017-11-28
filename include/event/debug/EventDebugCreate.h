#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class IMessage;


class EventDebugCreate : public IMessageEvent {
    public:
        EventDebugCreate() = default;
        ~EventDebugCreate() = default;

    public:
        void run(IMessage& message) const override;
};


} // End namespace
