#include "messaging/MessageRouter.h"
#include "messaging/MessageRoute.h"
#include "messaging/MessageAbsFactory.h"
#include "messaging/Message.h"
#include "messaging/MessageEvent.h"

#include <elephant.h>

using namespace collab;


MessageRouter::MessageRouter(MessageAbsFactory& factory)
    : m_messageFactory(factory) {
}


void MessageRouter::addRoute(const int messageType, const MessageEvent* event) {
    static MessageRoute route(messageType, event);
    LOG_DEBUG(0, "Add route for message type %d with event %a", messageType, event);
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

    Message *m = this->m_messageFactory.newMessage(messageType);
    //m->deserialize(); // TODO

    const MessageEvent* e = route->getMessageEvent();
    e->run(*m);

    delete m; // Important since newMessage allocate with new
}


