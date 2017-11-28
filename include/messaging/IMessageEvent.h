#pragma once


namespace collab {

class IMessage;


/**
 * Interface for message handling.
 * Template for each concret message
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class IMessageEvent {
    protected:
        IMessageEvent() = default;
    public:
        virtual ~IMessageEvent() = default;

    public:
        /**
         * Execute this event for the given message.
         * This applies event logic.
         *
         * \param message The message to use for the event.
         */
        virtual void run(IMessage & message) const = 0;
};


} // End namespace
