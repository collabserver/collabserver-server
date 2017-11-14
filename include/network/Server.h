#pragma once


namespace collab {


/**
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
class Server {
    private:
        bool isRunning;

    public:
        Server();
        ~Server();

    public:
        void start();
        void stop();
};


} // End namespace
