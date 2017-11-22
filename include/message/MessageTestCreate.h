#pragma once

#include "Message.h"

namespace collab {


class MessageTestCreate : public Message {
    public:
        MessageTestCreate() = default;
        ~MessageTestCreate() = default;

    private:
        char* m_location;
        char* m_name;
};


} // End namespace
