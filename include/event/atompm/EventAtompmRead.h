#pragma once

#include "messaging/MessageEvent.h"


namespace collab {

class Message;


class EventAtompmRead : public MessageEvent {
    public:
        EventAtompmRead() = default;

    public:
        void run(Message& message) const override;
};


} // End namespace
