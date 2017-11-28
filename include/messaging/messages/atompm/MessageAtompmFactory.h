#pragma once

#include "messaging/MessageAbsFactory.h"


namespace collab {


/**
 * Concrete method factory for AtomPM messages type.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageAtompmFactory : public MessageAbsFactory {
    public:
        MessageAtompmFactory() = default;
        ~MessageAtompmFactory() = default;

    public:
        IMessage* newMessage(const int type) const override;
};


} // End namespace
