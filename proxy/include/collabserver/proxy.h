#pragma once


namespace collab {


/*
 * This is the main (And only) end user class.
 * Gives all end user functions relative to remote collab server.
 *
 * author:  Constantin Masson
 * date:    Feb 208
 */
class Proxy {
    public:
        Proxy() = default;
        ~Proxy() = default;

    public:
        /**
         * Try to open connection with the remote server.
         *
         * \param ip IP of the remove server.
         * \param port Port of the remove server.
         * \param timeout Fails to connect if longer than timeout (No timeout if <=0)
         * \return True if successfully connected, otherwise, return false
         */
        bool connect(const char* ip, const int port, const int timeout = 0);

        /**
         * Stop connection with remove server.
         *
         * \return True if successfully disconnected, otherwise, return false
         */
        bool disconnect();

        /**
         * Load the requested view from the server.
         * This function is asynchrone and won't wait for answer.
         *
         * \param viewID ID of the view to load.
         */
        void loadView(const int viewID); //TODO Add callback function
};


} // End namespace
