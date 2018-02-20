#pragma once


namespace collab {


/*
 * This is the main (And only) end user class.
 * Gives all end-user functions to use the collaborative server.
 *
 * author:  Constantin Masson
 * date:    Feb 208
 */
class Proxy {
    public:
        Proxy() = default;
        ~Proxy();

    public:
        /**
         * Try to open connection with the remote server.
         * Connection tentative may be timed out if timeout is set.
         *
         * \param ip IP of the remove server.
         * \param port Port of the remove server.
         * \param timeout Connection timeout in seconds.
         * \return True if successfully connected, otherwise, return false
         */
        bool connect(const char* ip, const int port, const float timeout = 0.0f);

        /**
         * Stop connection with remove server.
         *
         * \return True if successfully disconnected, otherwise, return false
         */
        bool disconnect();

        /**
         * Load the requested view from the server.
         * This function is asynchrony and won't wait for answer.
         *
         * \param viewID ID of the view to load.
         */
        void loadView(const int viewID); //TODO Add callback function
};


} // End namespace
