#include "messaging/event/view/request/LoadById.h"

#include "elephantlogger/log.h"


using namespace collab;
namespace msg = messaging::message::view::request;
namespace handler = messaging::event::view::request;


void handler::LoadById::receive(msg::LoadById & message) const {
    LOG_DEBUG(0, "Receive VIEW_REQUEST_LOAD_BY_ID");
    // TODO
    // Add un DB fowarded msg list
    // Foward to DB
    // etc etc etc blablabla
    // Drink the Beer when it's done
}
