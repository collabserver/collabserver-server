/*
 * SERVER MESSAGE FACTORY
 * Implementation of the Message factory.
 * Only message available for the component may be created.
 */
#include "messaging/MessageFactory.h"

#include "messaging/message/view/request/LoadById.h"
#include "messaging/message/view/response/LoadById.h"

#include "messaging/event/view/request/LoadById.h"


using namespace collab;

// Namespace alias
namespace view_msg = message::view;
namespace view_event = event::view;


// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

std::unique_ptr<IMessage> MessageFactory::newMessage(const MessageTypes type) const {
    // DevNote: if pass to C++14, may use std::make_unique instead
    // DevNote: Switch-case is actually flexible enough and fast for this use-case.

    switch(type) {

        // ---------------------------------------------------------------------
        // View Messages
        // ---------------------------------------------------------------------
        case MessageTypes::VIEW_REQUEST_LOAD_BY_ID:
            static view_event::request::LoadById coco;
            return std::unique_ptr<IMessage>(new view_msg::request::LoadById(&coco));

        case MessageTypes::VIEW_RESPONSE_LOAD_BY_ID:
            return std::unique_ptr<IMessage>(new view_msg::response::LoadById());


        // ---------------------------------------------------------------------
        // Miscellaneous Messages
        // ---------------------------------------------------------------------
        default:
            return nullptr;
    }
}

