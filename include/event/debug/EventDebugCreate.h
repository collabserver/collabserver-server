#pragma once

#include "messaging/MessageEvent.h"


namespace collab {

class Message;


class EventDebugCreate : public MessageEvent {
    public:
        EventDebugCreate() = default;

    public:
        void run(Message& message) const override;
};


} // End namespace
