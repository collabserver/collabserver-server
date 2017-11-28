#pragma once

#include "messaging/MessageEvent.h"


namespace collab {

class Message;


class EventAtompmUpdate : public MessageEvent {
    public:
        EventAtompmUpdate() = default;

    public:
        void run(Message& message) const override;
};


} // End namespace
