#pragma once

#include <cstring> // size_t

namespace collab {


class MessageFactory;


/**
 * Component that listen for message comming over the network.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
class MessageListener {
    private:
        bool m_isRunning = false;

    public:
        MessageListener() = default;

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

