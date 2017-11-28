#pragma once

#include "messaging/Message.h"


namespace collab {


class MessageDebugRead : public Message {
    public:
        MessageDebugRead() = default;
        ~MessageDebugRead() = default;
};


} // End namespace
