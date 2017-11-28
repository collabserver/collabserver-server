#pragma once

#include "messaging/Message.h"


namespace collab {


class MessageDebugUpdate : public Message {
    public:
        MessageDebugUpdate() = default;
        ~MessageDebugUpdate() = default;
};


} // End namespace
