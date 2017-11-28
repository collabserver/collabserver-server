#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class IMessage;


class EventDebugDelete : public IMessageEvent {
    public:
        EventDebugDelete() = default;
        ~EventDebugDelete() = default;

    public:
        void run(IMessage& message) const override;
};


} // End namespace
