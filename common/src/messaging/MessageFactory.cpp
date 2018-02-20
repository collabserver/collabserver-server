#include "messaging/MessageFactory.h"
#include "messaging/MessageTypes.h"

#include "messaging/messages/MessageCreate.h"
#include "messaging/messages/MessageDelete.h"
#include "messaging/messages/MessageRead.h"
#include "messaging/messages/MessageUpdate.h"


using namespace collab;


std::unique_ptr<IMessage> MessageFactory::newMessage(const MessageTypes type) const {
    // Switch-case is actually flexible enough and fast for this use-case.
    switch(type) {
        case MessageTypes::Create:
            // TODO: DevNote: if pass to C++14, may use std::make_unique instead
            return std::unique_ptr<IMessage>(new MessageCreate());

        case MessageTypes::Delete:
            return std::unique_ptr<IMessage>(new MessageDelete());

        case MessageTypes::Read:
            return std::unique_ptr<IMessage>(new MessageRead());

        case MessageTypes::Update:
            return std::unique_ptr<IMessage>(new MessageUpdate());

        default:
            return nullptr;
    }
}
