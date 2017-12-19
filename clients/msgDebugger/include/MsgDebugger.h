#pragma once


#include "ServerProxy.h"


namespace collab {


class MsgDebugger {
    private:
        bool m_isRunning        = false;
        ServerProxy m_proxy;

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
