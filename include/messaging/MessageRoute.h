#pragma once

#include <elephant.h>


namespace collab {

class MessageEvent;


class MessageRoute {
    private:
        const int m_messageType;
        const MessageEvent* m_messageEvent = nullptr;

    public:
        MessageRoute() = delete;

        MessageRoute(const int type, const MessageEvent* event)
            : m_messageType(type),
              m_messageEvent(event) {
        }

    public:
        const int getMessageType() const {
            return this->m_messageType;
        }

        const MessageEvent* getMessageEvent() const {
            return this->m_messageEvent;
        }
};


} // End namespace
