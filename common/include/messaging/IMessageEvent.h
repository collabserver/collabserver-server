#pragma once


namespace collab {


/**
 * Interface for message handling.
 * Incoming message may start a callback function in order to process it.
 * Message may register the MessageEvent handler that is in charge to do this.
 *
 * \tparam <M> The message this event is working with.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
template<class M>
class IMessageEvent {
    protected:
        IMessageEvent() = default;
    public:
        virtual ~IMessageEvent() = default;

    public:
        /**
         * Execute message logic for the newly received message.
         *
         * \param message The message to use for the event.
         */
        virtual void receive(M & message) const = 0;
};


} // End namespace
