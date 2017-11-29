#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageDebugDelete;


class EventDebugDelete : public IMessageEvent<MessageDebugDelete> {
    public:
        EventDebugDelete() = default;
        ~EventDebugDelete() = default;

    public:
        void receive(MessageDebugDelete & message) const override;
};


} // End namespace
