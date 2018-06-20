#pragma once

#include "collabclient/Client.h"

namespace collab {


/**
 * TODO
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
class MsgDebugger {
    private:
        bool _isRunning = false;
        Client _client;

    public:
        MsgDebugger() = default;
        ~MsgDebugger() = default;

    public:
        void run();
        void stop();

    private:
        void sendDummyMessage(const int type) const;
};


} // End namespace


