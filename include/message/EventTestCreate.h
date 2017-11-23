#pragma once

#include "Event.h"
#include "MessageTestCreate.h"


namespace collab {


class EventTestCreate : public Event<MessageTestCreate> {
    public:
        EventTestCreate() = default;

    public:
        void run(MessageTestCreate& message) override;
};


} // End namespace
