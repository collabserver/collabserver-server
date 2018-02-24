/*
 * PROXY MESSAGE FACTORY
 * Implementation of the Message factory.
 * Only message available for this component may be created.
 */

#include "messaging/MessageFactory.h"

#include "messaging/message/view/request/LoadById.h"
#include "messaging/message/view/response/LoadById.h"


using namespace collab;


std::unique_ptr<IMessage> MessageFactory::newMessage(const MessageTypes type) const {
    // DevNote: if pass to C++14, may use std::make_unique instead
    // DevNote: Switch-case is actually flexible enough and fast for this use-case.

    switch(type) {

        // ---------------------------------------------------------------------
        // View Messages
        // ---------------------------------------------------------------------
        namespace view = message::view;

        case MessageTypes::VIEW_REQUEST_LOAD_BY_ID:
            return std::unique_ptr<IMessage>(new view::request::LoadById(nullptr));

        case MessageTypes::VIEW_RESPONSE_LOAD_BY_ID:
            return std::unique_ptr<IMessage>(new view::response::LoadById());


        // ---------------------------------------------------------------------
        // Miscellaneous Messages
        // ---------------------------------------------------------------------
        default:
            return nullptr;
    }
}


