#pragma once

#include "messaging/Message.h"


namespace collab {


class MessageAtompmRead : public Message {
    public:
        MessageAtompmRead() = default;
        ~MessageAtompmRead() = default;
};


} // End namespace
