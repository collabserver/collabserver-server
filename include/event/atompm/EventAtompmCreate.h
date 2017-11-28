#pragma once

#include "messaging/MessageEvent.h"


namespace collab {

class Message;


class EventAtompmCreate : public MessageEvent {
    public:
        EventAtompmCreate() = default;

    public:
        void run(Message& message) const override;
};


} // End namespace
