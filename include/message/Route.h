#pragma once

#include "Event.h"


namespace collab {


class Route {
    private:
        const int m_messageType;
        const Event* m_event = nullptr;

    public:
        Route() = delete;

        Route(const int messageType, const Event* event)
            : m_messageType(messageType),
              m_event(event) {
        }

    public:
        const int getMessageType() const {
            return this->m_messageType;
        }

        const Event* getEvent() const {
            return this->m_event;
        }
};


} // End namespace
