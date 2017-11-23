#include "message/Router.h"
#include "message/MessageTestFactory.h"
#include "message/Route.h"
#include "message/EventTestCreate.h"


#include <logger/elephant.h>

using namespace collab;


Router::Router() {
    //TODO Temp for test
    static EventTestCreate eventTestCreate;
    this->addRoute(3, &eventTestCreate);
}

void Router::addRoute(const int messageType, const Event* event) {
    static Route route(messageType, event);
    this->m_lookupRoutes.emplace(messageType, route);
}


void Router::processMessage(const char* msg, const size_t size) const {
    LOG_DEBUG(0, "Router process message. Raw message (size %d): %s", size, msg);

    int messageType = static_cast<int>(msg[0]);
    LOG_DEBUG(0, "Recovered type: %d", messageType);
    const Route* route = nullptr;

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
    MessageTestFactory factory;
    Message *m = factory.newMessage(messageType);
    //m->deserialize(); // TODO

    //TODO Call handler
    const Event* e = route->getEvent();
    e->run(*m);
    delete m; // Important since newMessage allocate with new
}


