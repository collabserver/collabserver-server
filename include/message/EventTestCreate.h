#pragma once

#include "Event.h"
#include "MessageTestCreate.h"


namespace collab {


class EventTestCreate : public Event {
    public:
        EventTestCreate() = default;

    public:
        void run(Message& message) const override;
};


} // End namespace
