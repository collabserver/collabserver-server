#pragma once

#include "util/Singleton.h"


namespace collab {

class MessageReceiver;


/**
 * Main component.
 * The collab server itself.
 *
 * \author  Constantin Masson
 * \date    Nov 2017
 */
class CollabServer : private Singleton<CollabServer> {
    private:
        MessageReceiver* m_messageReceiver = nullptr;

    private:
        friend Singleton<CollabServer>;
        CollabServer() = default;
        ~CollabServer() = default;

    public:
        using Singleton<CollabServer>::getInstance;

    public:
        void init();
        void start();
        void stop();
};


} // End namespace
