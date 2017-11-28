#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class IMessage;


class EventAtompmDelete : public IMessageEvent {
    public:
        EventAtompmDelete() = default;
        ~EventAtompmDelete() = default;

    public:
        void run(IMessage& message) const override;
};


} // End namespace
