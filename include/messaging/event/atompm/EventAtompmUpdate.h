#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageAtompmUpdate;

class EventAtompmUpdate : public IMessageEvent<MessageAtompmUpdate> {
    public:
        EventAtompmUpdate() = default;
        ~EventAtompmUpdate() = default;

    public:
        void receive(MessageAtompmUpdate & message) const override;
};


} // End namespace
