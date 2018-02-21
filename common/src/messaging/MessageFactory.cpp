#include "messaging/MessageFactory.h"
#include "messaging/MessageTypes.h"

#include "messaging/message/MessageViewLoadById.h"


using namespace collab;


std::unique_ptr<IMessage> MessageFactory::newMessage(const MessageTypes type) const {
    // Switch-case is actually flexible enough and fast for this use-case.
    switch(type) {
        case MessageTypes::VIEW_LOAD_BY_ID:
            // TODO: DevNote: if pass to C++14, may use std::make_unique instead
            return std::unique_ptr<IMessage>(new MessageViewLoadById());

        default:
            return nullptr;
    }
}
