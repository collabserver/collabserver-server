#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageDelete;


/**
 * Defines an event for MessageDelete type.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class EventDelete : public IMessageEvent<MessageDelete> {
    public:
        EventDelete() = default;
        ~EventDelete() = default;

    public:
        void receive(MessageDelete & message) const override;
};


} // End namespace
