#pragma once

#include "MessageTypes.h"

#include <sstream>


namespace collab {


/**
 * Interface for Messages.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class IMessage {
    protected:
        IMessage() = default;
    public:
        virtual ~IMessage() = default;

    public:
        /**
         * Apply the event registered for this message.
         */
        virtual void apply() = 0;

        /**
         * Serialize the message in internal packed format.
         *
         * \param buffer Where to place serialized data.
         * \return True if successfully serialized, otherwise, return false.
         */
        virtual bool serialize(std::stringstream & buffer) const = 0;

        /**
         *
         * Unserialize the message from its internal packed format.
         *
         * \param buffer Where to place unserialized data.
         * \return True if successfully unserialized, otherwise, return false.
         */
        virtual bool unserialize(std::stringstream & buffer) = 0;

        /**
         * Get the message type ID. (From enum).
         *
         * \return Type of the message.
         */
        virtual MessageTypes getType() const = 0;
};


} // End namespace
