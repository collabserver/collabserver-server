#pragma once

#include "messaging/MessageEvent.h"


namespace collab {

class Message;


class EventDebugUpdate : public MessageEvent {
    public:
        EventDebugUpdate() = default;

    public:
        void run(Message& message) const override;
};


} // End namespace

