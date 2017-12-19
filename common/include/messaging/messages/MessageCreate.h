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
        int m_a = 10;
        int m_b = 20;
        bool m_c = true;

    public:
        void apply() override;
        bool serialize(std::stringstream & buffer) const override;
        bool unserialize(std::stringstream & buffer) override;
        MessageTypes getType() const override;
};


} // End namespace
