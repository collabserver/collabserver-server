#pragma once

#include "messaging/MessageEvent.h"


namespace collab {

class Message;


class EventDebugDelete : public MessageEvent {
    public:
        EventDebugDelete() = default;

    public:
        void run(Message& message) const override;
};


} // End namespace
