#include "core/CollabServer.h"

#include "messaging/MessageRouter.h"
#include "network/MessageReceiver.h"
#include "message/debug/MessageDebugFactory.h"
#include "event/debug/EventDebugCreate.h"

using namespace collab;


void CollabServer::init() {
    // Create router for specific messages protocol
    static MessageDebugFactory  factory;
    static MessageRouter        router(factory);
    static MessageReceiver      receiver(router);
    this->m_messageReceiver     = &receiver;

    // Add all routes for the MessageRouter.
    static EventDebugCreate eventDebugCreate;
    router.addRoute(3, &eventDebugCreate);
}

void CollabServer::start() {
    this->m_messageReceiver->start();
}

void CollabServer::stop() {
    this->m_messageReceiver->stop();
}
