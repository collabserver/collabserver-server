#pragma once


namespace collab {

class MessageRouter;


/**
 * Component that listen for message comming over the network.
 * Message are handled by a message router.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
class MessageReceiver {
    private:
        bool m_isRunning;
        MessageRouter& m_messageRouter;

    public:
        MessageReceiver(MessageRouter& messageRouter);
        ~MessageReceiver();

    public:
        /**
         * Start listening.
         *
         * \note
         * This function block until this component is stopped
         * from another thread.
         */
        void start();

        /**
         * Stop listening.
         */
        void stop();
};


} // End namespace
