/*
 * PROXY MESSAGE FACTORY
 * Implementation of the Message factory.
 * Only message available for this component may be created.
 */

#include "messaging/MessageFactory.h"

#include "messaging/message/view/request/LoadById.h"
#include "messaging/message/view/response/LoadById.h"


using namespace collab;

// Namespace alias
namespace view_msg = messaging::message::view;


std::unique_ptr<IMessage> MessageFactory::newMessage(const MessageTypes type) const {
    // DevNote: if pass to C++14, may use std::make_unique instead
    // DevNote: Switch-case is actually flexible enough and fast for this use-case.

    switch(type) {

        // ---------------------------------------------------------------------
        // View Messages
        // ---------------------------------------------------------------------
        case MessageTypes::VIEW_REQUEST_LOAD_BY_ID:
            return std::unique_ptr<IMessage>(new view_msg::request::LoadById(nullptr));

        case MessageTypes::VIEW_RESPONSE_LOAD_BY_ID:
            return std::unique_ptr<IMessage>(new view_msg::response::LoadById(nullptr));


        // ---------------------------------------------------------------------
        // Miscellaneous Messages
        // ---------------------------------------------------------------------
        default:
            return nullptr;
    }
}


