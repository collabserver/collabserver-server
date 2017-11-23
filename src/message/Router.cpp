#include "message/Router.h"
#include "message/MessageTestFactory.h"
#include "message/Route.h"
#include "message/EventTestCreate.h"


#include <logger/elephant.h>

using namespace collab;


Router::Router() {
    static EventTestCreate eventTestCreate;
    //static Route routeMsgCreate(&eventTestCreate);
    //this->m_lookupRoutes
}


void Router::processMessage(const char* msg, const size_t size) const {
    LOG_DEBUG(0, "Message received by Router: ");
    LOG_DEBUG(0, msg);

    int messageType = static_cast<int>(msg[0]);

    try {
        int r = this->m_lookupRoutes.at(messageType);
    }
    catch(std::out_of_range &e) {
        // TODO
        LOG_DEBUG(0, "No route found");
        return;
    }
    LOG_DEBUG(0, "Route found");

    //TODO Recover actual message representation (Message*)
    MessageTestFactory factory;
    Message *m = factory.newMessage(messageType);
    //m->deserialize(); // TODO

    //TODO Call handler
    //r.getHandler().apply(r);
}
