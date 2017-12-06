#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageCreate;


/**
 * Defines an event for MessageCreate type.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class EventCreate : public IMessageEvent<MessageCreate> {
    public:
        EventCreate() = default;
        ~EventCreate() = default;

    public:
        void receive(MessageCreate & message) const override;
};


} // End namespace
