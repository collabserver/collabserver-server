#include "core/CollabServer.h"

#include "network/MessageReceiver.h"
#include "messaging/MessageRouter.h"

// Debug messaging
#include "event/debug/EventDebugCreate.h"
#include "event/debug/EventDebugDelete.h"
#include "event/debug/EventDebugRead.h"
#include "event/debug/EventDebugUpdate.h"
#include "message/debug/MessageDebugFactory.h"

// Atom messaging
#include "event/atompm/EventAtompmCreate.h"
#include "event/atompm/EventAtompmDelete.h"
#include "event/atompm/EventAtompmRead.h"
#include "event/atompm/EventAtompmUpdate.h"
#include "message/atompm/MessageAtompmFactory.h"

using namespace collab;



// TODO: tmp function that init server with AtomPM messaging system
static MessageReceiver* initAtompmMessaging() {
    static MessageAtompmFactory  factory;
    static MessageRouter        router(factory);
    static MessageReceiver      receiver(router);

    // Add all routes for the MessageRouter.
    static EventAtompmCreate     eventCreate;
    static EventAtompmDelete     eventDelete;
    static EventAtompmRead       eventRead;
    static EventAtompmUpdate     eventUpdate;

    router.addRoute(static_cast<int>(MessageAtompmTypes::Create),   &eventCreate);
    router.addRoute(static_cast<int>(MessageAtompmTypes::Delete),   &eventDelete);
    router.addRoute(static_cast<int>(MessageAtompmTypes::Read),     &eventRead);
    router.addRoute(static_cast<int>(MessageAtompmTypes::Update),   &eventUpdate);

    return &receiver;
}

// TODO: temporary function that init server with Debug messaging system
static MessageReceiver* initDebugMessaging() {
    static MessageDebugFactory  factory;
    static MessageRouter        router(factory);
    static MessageReceiver      receiver(router);

    // Add all routes for the MessageRouter.
    static EventDebugCreate     eventCreate;
    static EventDebugDelete     eventDelete;
    static EventDebugRead       eventRead;
    static EventDebugUpdate     eventUpdate;

    router.addRoute(static_cast<int>(MessageDebugTypes::Create),    &eventCreate);
    router.addRoute(static_cast<int>(MessageDebugTypes::Delete),    &eventDelete);
    router.addRoute(static_cast<int>(MessageDebugTypes::Read),      &eventRead);
    router.addRoute(static_cast<int>(MessageDebugTypes::Update),    &eventUpdate);

    return &receiver;
}


void CollabServer::init() {
    this->m_messageReceiver = initDebugMessaging();
    //this->m_messageReceiver = initAtompmMessaging();
}

void CollabServer::start() {
    this->m_messageReceiver->start();
}

void CollabServer::stop() {
    this->m_messageReceiver->stop();
}
