#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageAtompmCreate;


class EventAtompmCreate : public IMessageEvent<MessageAtompmCreate> {
    public:
        EventAtompmCreate() = default;
        ~EventAtompmCreate() = default;

    public:
        void receive(MessageAtompmCreate & message) const override;
};


} // End namespace
