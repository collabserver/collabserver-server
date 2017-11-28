#pragma once

#include "messaging/MessageEvent.h"


namespace collab {

class Message;


class EventDebugRead : public MessageEvent {
    public:
        EventDebugRead() = default;

    public:
        void run(Message& message) const override;
};


} // End namespace

