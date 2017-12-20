#pragma once


#include "collabserver/proxy.h"


namespace collab {


class DatabaseDebugger {
    private:
        bool m_isRunning = false;
        ServerProxy m_proxy;

    public:
        void run();
        void stop();
};


} // End namespace
