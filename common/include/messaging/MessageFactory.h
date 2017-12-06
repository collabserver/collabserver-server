#pragma once


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
class MessageFactory {
    public:
        MessageFactory() = default;
        ~MessageFactory() = default;

    public:
        /**
         * Create a new concrete message from its ID.
         *
         * \warning
         * Message is allocated on the head (Using C++ new operator).
         * This message must be free manually!
         *
         * \return New concrete message created. (Or null if invalid type).
         */
        IMessage* newMessage(const int type) const;
};


} // End namespace
