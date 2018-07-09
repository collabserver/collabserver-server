#include "collabcommon/messaging/MessageFactory.h"

#include "collabcommon/messaging/Message.h"

namespace collab {


std::unique_ptr<Message> MessageFactory::newMessage(const int type) const {
    // DevNote: if pass to C++14, may use std::make_unique instead
    // DevNote: Switch-case is actually flexible enough and fast for this use-case.

    switch(type) {
        case DEBUG_MSG:
            return nullptr;


        // ---------------------------------------------------------------------
        // Miscellaneous Messages
        // ---------------------------------------------------------------------
        default:
            return nullptr;
    }
}


}  // End namespace


