#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {
class MessageViewLoadById;


/**
 * Implements IMessageEvent for Read Message reception.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class EventViewLoadById : public IMessageEvent<MessageViewLoadById> {
    public:
        EventViewLoadById() = default;
        ~EventViewLoadById() = default;

    public:
        void receive(MessageViewLoadById & message) const override;
};


} // End namespace
