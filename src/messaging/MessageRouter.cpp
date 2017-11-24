#include "messaging/MessageRouter.h"
#include "messaging/MessageRoute.h"
#include "messaging/Message.h"

#include "event/debug/EventDebugCreate.h"
#include "message/debug/MessageDebugFactory.h"

#include <logger/elephant.h>

using namespace collab;


MessageRouter::MessageRouter() {
    //TODO Temp for test
    static EventDebugCreate eventDebugCreate;
    this->addRoute(3, &eventDebugCreate);
}

void MessageRouter::addRoute(const int messageType, const MessageEvent* event) {
    static MessageRoute route(messageType, event);
    this->m_lookupRoutes.emplace(messageType, route);
}


void MessageRouter::processMessage(const char* msg, const size_t size) const {
    LOG_DEBUG(0, "Router process message. Raw message (size %d): %s", size, msg);

    int messageType = static_cast<int>(msg[0]);
    LOG_DEBUG(0, "Recovered type: %d", messageType);
    const MessageRoute* route = nullptr;

    try {
        route = &this->m_lookupRoutes.at(messageType);
    }
    catch(std::out_of_range &e) {
        // TODO
        LOG_DEBUG(0, "No route found for message type %d", messageType);
        return;
    }
    LOG_DEBUG(0, "Route found for message type %d", messageType);

    //TODO Recover actual message representation (Message*)
    MessageDebugFactory factory;
    Message *m = factory.newMessage(messageType);
    //m->deserialize(); // TODO

    //TODO Call handler
    const MessageEvent* e = route->getMessageEvent();
    e->run(*m);
    delete m; // Important since newMessage allocate with new
}


