#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class IMessage;


class EventAtompmCreate : public IMessageEvent {
    public:
        EventAtompmCreate() = default;
        ~EventAtompmCreate() = default;

    public:
        void run(IMessage& message) const override;
};


} // End namespace
