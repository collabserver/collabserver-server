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
        template<class Stream> bool serialize(Stream & buffer) const;
        template<class Stream> bool unserialize(Stream & buffer) const;
};


} // End namespace
