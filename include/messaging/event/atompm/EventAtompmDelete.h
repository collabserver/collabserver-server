#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageAtompmDelete;


class EventAtompmDelete : public IMessageEvent<MessageAtompmDelete> {
    public:
        EventAtompmDelete() = default;
        ~EventAtompmDelete() = default;

    public:
        void receive(MessageAtompmDelete & message) const override;
};


} // End namespace
