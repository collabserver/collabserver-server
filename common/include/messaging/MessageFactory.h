#pragma once

#include "MessageTypes.h"
#include "utils/Singleton.h"

#include <memory> // std::unique_ptr


namespace collab {

class IMessage;


/**
 * Factory for messages.
 * Each message has a special ID.
 * Factory may return the specific message implementation from its ID.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageFactory : private Singleton<MessageFactory> {
    // Use for singleton
    private:
        friend Singleton<MessageFactory>;
    public:
        using Singleton<MessageFactory>::getInstance;


    // Abstract class factory
    protected:
        MessageFactory() = default;
        ~MessageFactory() = default;


    public:
        /**
         * Create a new concrete message from its ID.
         * If ID is not valid, nullptr is returned.
         *
         * \return Smart pointer to the new created Message.
         */
        std::unique_ptr<IMessage> newMessage(const MessageTypes type) const;
};


} // End namespace
