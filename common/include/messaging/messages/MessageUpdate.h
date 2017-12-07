#pragma once

#include "messaging/IMessage.h"
#include "messaging/events/EventUpdate.h"


namespace collab {


/**
 * Implements IMessage for Update operation.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageUpdate : public IMessage {
    private:
        /** Event that process this message. */
        EventUpdate m_event;

    public:
        MessageUpdate() = default;
        ~MessageUpdate() = default;

    public:
        void apply() override;
        template<class Stream> bool serialize(Stream & buffer) const;
        template<class Stream> bool unserialize(Stream & buffer) const;
};


} // End namespace
