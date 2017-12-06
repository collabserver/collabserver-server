#pragma once


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
};


} // End namespace
