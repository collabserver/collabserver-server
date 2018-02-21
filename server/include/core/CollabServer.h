#pragma once

#include "util/Singleton.h"
#include "network/MessageReceiver.h"


namespace collab {


/**
 * Main component.
 * The collab Server itself.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 * \since   0.1.0
 */
class CollabServer : private Singleton<CollabServer> {
    private:
        MessageReceiver m_messageReceiver;

    private:
        friend Singleton<CollabServer>;
        CollabServer() = default;
        ~CollabServer() = default;

    public:
        using Singleton<CollabServer>::getInstance;

    public:
        void start();
        void stop();
};


} // End namespace
