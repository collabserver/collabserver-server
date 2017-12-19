#pragma once

#include <zmq.hpp>


namespace collab {
class IMessage;


/**
 * Utility methods for Messages communication over network.
 * Abstract class with only static functions.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 * \since   0.1.0
 */
class MessageHelper {
    private:
        MessageHelper() = delete;
        ~MessageHelper() = delete;

    public:
        /**
         * Send the given message on the socket.
         * This doesn't block.
         *
         * \param socket Socket where to send message.
         * \param msg The message to send.
         */
        static void sendMessage(zmq::socket_t & socket, const IMessage & msg);

        /**
         * Process a raw network message.
         * Message has the network format (Bitpacking or whatever the network is using).
         * This unserialize the message and call back the event according to msg.
         *
         * \note
         * Message is not a null terminated string.
         * Given size is used instead.
         *
         * \note
         * Do nothing if message is not valid (Bad format, unkown type...)
         *
         * \param msg Raw content of the message received.
         * \param size Size of the message.
         */
        static void processMessage(const char* msg, const size_t size);
};


} // End namespace


