#pragma once


namespace collab {

class IMessageEvent;


/**
 * Interface for Messages.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class IMessage {
    protected:
        /** Event that process this message. */
        IMessageEvent* m_event;

    protected:
        IMessage() = default;

    public:
        virtual ~IMessage() = default;

    public:

        /**
         * Apply the event registered for this message.
         */
        virtual void apply() = 0;
};


} // End namespace
