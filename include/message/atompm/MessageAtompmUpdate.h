#pragma once

#include "messaging/Message.h"


namespace collab {


class MessageAtompmUpdate : public Message {
    public:
        MessageAtompmUpdate() = default;
        ~MessageAtompmUpdate() = default;
};


} // End namespace
