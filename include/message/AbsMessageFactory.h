#pragma once

#include "Message.h"


namespace collab {


class AbsMessageFactory {
    protected:
        AbsMessageFactory() = default;
        virtual ~AbsMessageFactory() = default;

    public:
        virtual Message* newMessage(const int type) const = 0;
        virtual int getMessageTypeCounter() const = 0;
};


} // End namespace
