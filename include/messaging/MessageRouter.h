#pragma once

#include "messaging/MessageRoute.h"

#include <unordered_map>
#include <cstring> // size_t

namespace collab {

class MessageAbsFactory;
class MessageEvent;


class MessageRouter {
    private:
        MessageAbsFactory& m_messageFactory;

    public:
        MessageRouter(MessageAbsFactory& factory);
        ~MessageRouter() = default;

    private:
        std::unordered_map<int, MessageRoute> m_lookupRoutes;

    public:
        void processMessage(const char* msg, const size_t size) const;
        void addRoute(const int messageType, const MessageEvent* event);
};


} // End namespace
