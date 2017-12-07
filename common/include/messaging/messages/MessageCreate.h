#pragma once

#include "messaging/IMessage.h"
#include "messaging/events/EventCreate.h"

#include <msgpack.hpp>


namespace collab {


/**
 * Implements IMessage for Create operation.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageCreate : public IMessage {
    private:
        /** Event that process this message. */
        EventCreate m_event;

    public:
        MessageCreate() = default;
        ~MessageCreate() = default;

    private:
        // TODO Some dummy data for now
        int a;
        int b;
        bool c;

    public:
        void apply() override;
        template<class Stream> bool serialize(Stream & buffer) const;
        template<class Stream> bool unserialize(Stream & buffer) const;
};


} // End namespace
