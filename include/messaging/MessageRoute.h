#pragma once


namespace collab {

class MessageEvent;


class MessageRoute {
    private:
        const int m_messageType;
        const MessageEvent* m_messageEvent = nullptr;

    public:
        MessageRoute() = delete;

        MessageRoute(const int messageType, const MessageEvent* MessageEvent)
            : m_messageType(messageType),
              m_messageEvent(MessageEvent) {
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
