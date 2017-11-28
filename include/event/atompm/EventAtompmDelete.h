#pragma once

#include "messaging/MessageEvent.h"


namespace collab {

class Message;


class EventAtompmDelete : public MessageEvent {
    public:
        EventAtompmDelete() = default;

    public:
        void run(Message& message) const override;
};


} // End namespace
