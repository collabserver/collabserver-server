#pragma once

#include "messaging/IMessage.h"
#include "messaging/events/EventDelete.h"


namespace collab {


/**
 * Implements IMessage for Delete operation.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageDelete : public IMessage {
    private:
        /** Event that process this message. */
        EventDelete m_event;

    public:
        MessageDelete() = default;
        ~MessageDelete() = default;

    public:
        void apply() override;
        template<class Stream> bool serialize(Stream & buffer) const;
        template<class Stream> bool unserialize(Stream & buffer) const;
};


} // End namespace
