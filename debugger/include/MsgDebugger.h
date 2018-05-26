#pragma once

#include <collabserver/proxy.h>


class MsgDebugger {
    private:
        bool m_isRunning        = false;
        collab::Proxy m_proxy;

    public:
        MsgDebugger() = default;
        ~MsgDebugger() = default;

    public:
        void run();
        void stop();

    private:
        void sendDummyMessage(const int type) const;
};
