#pragma once

#include "messaging/Message.h"


namespace collab {


class MessageDebugCreate : public Message {
    public:
        MessageDebugCreate() = default;
        ~MessageDebugCreate() = default;

    private:
        char* m_location;
        char* m_name;
};


} // End namespace
