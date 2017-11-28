#pragma once

#include "messaging/Message.h"


namespace collab {


class MessageAtompmDelete : public Message {
    public:
        MessageAtompmDelete() = default;
        ~MessageAtompmDelete() = default;
};


} // End namespace
