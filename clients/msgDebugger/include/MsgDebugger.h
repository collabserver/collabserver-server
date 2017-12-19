#pragma once


#include "ServerProxy.h"


namespace collab {


class MsgDebugger {
    private:
        bool m_isRunning        = false;
        ServerProxy m_proxy     = {"localhost", 5555};

    public:
        MsgDebugger() = default;
        ~MsgDebugger() = default;

    public:
        void run();
        void stop();
};


} // End namespace
