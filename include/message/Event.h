#pragma once

#include "Message.h"


namespace collab {


template<class M>
class Event {
    protected:
        Event() = default;
    public:
        virtual ~Event() = default;

    public:
        virtual void run(M& message) = 0;
};


}
