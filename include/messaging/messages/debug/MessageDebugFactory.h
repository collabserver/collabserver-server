#pragma once

#include "messaging/MessageAbsFactory.h"


namespace collab {


/**
 * Concrete method factory for Debug messages type.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageDebugFactory : public MessageAbsFactory {
    public:
        MessageDebugFactory() = default;
        ~MessageDebugFactory() = default;

    public:
        IMessage* newMessage(const int type) const override;
};


} // End namespace
