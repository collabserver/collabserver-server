#pragma once

namespace collab {


/**
 * Component that listen for message comming over the network.
 */
class Server {
    private:
        bool _isRunning = false;

    public:
        Server() = default;

    public:
        void start();
        void stop();
};


} // End namespace

