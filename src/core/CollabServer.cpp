#include "core/CollabServer.h"

using namespace collab;


void CollabServer::start() {
    this->m_messageReceiver.start();
}

void CollabServer::stop() {
    this->m_messageReceiver.stop();
}
