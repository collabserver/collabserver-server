#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class IMessage;


class EventAtompmUpdate : public IMessageEvent {
    public:
        EventAtompmUpdate() = default;
        ~EventAtompmUpdate() = default;

    public:
        void run(IMessage& message) const override;
};


} // End namespace
