#pragma once

#include "messaging/Message.h"


namespace collab {


class MessageDebugDelete : public Message {
    public:
        MessageDebugDelete() = default;
        ~MessageDebugDelete() = default;
};


} // End namespace
