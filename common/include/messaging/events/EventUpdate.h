#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageUpdate;


/**
 * Defines an event for MessageUpdate type.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class EventUpdate : public IMessageEvent<MessageUpdate> {
    public:
        EventUpdate() = default;
        ~EventUpdate() = default;

    public:
        void receive(MessageUpdate & message) const override;
};


} // End namespace
