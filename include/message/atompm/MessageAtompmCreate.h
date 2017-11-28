#pragma once

#include "messaging/Message.h"


namespace collab {


class MessageAtompmCreate : public Message {
    public:
        MessageAtompmCreate() = default;
        ~MessageAtompmCreate() = default;
};


} // End namespace
