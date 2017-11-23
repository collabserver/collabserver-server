#pragma once

#include "Message.h"


namespace collab {


class Event {
    protected:
        Event() = default;
    public:
        virtual ~Event() = default;

    public:
        virtual void run(Message& message) const = 0;
};


} // End namespace
