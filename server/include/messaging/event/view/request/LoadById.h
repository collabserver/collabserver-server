#pragma once

#include "messaging/IMessageEvent.h"
#include "messaging/message/view/request/LoadById.h"


namespace msg = collab::message::view::request;

namespace collab {
namespace event {
namespace view {
namespace request {


class LoadById : public IMessageEvent<msg::LoadById> {
    public:
        LoadById() = default;
        ~LoadById() = default;

    public:
        void receive(msg::LoadById & message) const override;
};


}}}} // End namespace
