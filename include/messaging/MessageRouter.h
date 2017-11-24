#pragma once

#include "messaging/MessageRoute.h"
#include "messaging/MessageEvent.h"

#include <unordered_map>
#include <cstring> // size_t

namespace collab {


class MessageRouter {
    public:
        MessageRouter();
        ~MessageRouter() = default;

    private:
        std::unordered_map<int, MessageRoute> m_lookupRoutes;

    public:
        void processMessage(const char* msg, const size_t size) const;
        void addRoute(const int messageType, const MessageEvent* event);
};


} // End namespace
