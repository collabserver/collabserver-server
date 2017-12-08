#pragma once

#include "messaging/IMessage.h"
#include "messaging/events/EventRead.h"


namespace collab {


/**
 * Implements IMessage for Read operation.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageRead : public IMessage {
    private:
        /** Event that process this message. */
        EventRead m_event;

    public:
        MessageRead() = default;
        ~MessageRead() = default;

    public:
        void apply() override;
        bool serialize(std::stringstream & buffer) const override;
        bool unserialize(std::stringstream & buffer) const override;
};


} // End namespace
