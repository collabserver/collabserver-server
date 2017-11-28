#pragma once


namespace collab {

class IMessage;


/**
 * Abstract factory for messages.
 * Each message has a special ID.
 * Factory may return the specific message implementation from its ID.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class MessageAbsFactory {
    protected:
        MessageAbsFactory() = default;
    public:
        virtual ~MessageAbsFactory() = default;

    public:
        /**
         * Create a new concrete message from its ID.
         *
         * \warning
         * Message is allocated on the head (Using C++ new operator).
         * This message must be free manually!
         *
         * \return New concrete message created.
         */
        virtual IMessage* newMessage(const int type) const = 0;
};


} // End namespace
