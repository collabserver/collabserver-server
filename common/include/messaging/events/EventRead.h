#pragma once

#include "messaging/IMessageEvent.h"


namespace collab {

class MessageRead;


/**
 * Implements IMessageEvent for Read Message reception.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class EventRead : public IMessageEvent<MessageRead> {
    public:
        EventRead() = default;
        ~EventRead() = default;

    public:
        void receive(MessageRead & message) const override;
};


} // End namespace
