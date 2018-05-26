#pragma once

#include "messaging/IMessage.h"
#include "messaging/IMessageEvent.h"


namespace collab {
namespace messaging {
namespace message {
namespace view {
namespace request {


/**
 * Implements IMessage for Read operation.
 * Load a specific view by its ID.
 *
 * \author  Constantin Masson
 * \date    Feb 2018
 * \since   0.1.0
 */
class LoadById : public IMessage {
    private:
        /** Event that process this message. */
        const IMessageEvent<LoadById> * const m_event = nullptr;

    public:
        LoadById(const IMessageEvent<LoadById> * event) : m_event(event) {}
        ~LoadById() = default;

    public:
        void apply() override;
        bool serialize(std::stringstream & buffer) const override;
        bool unserialize(std::stringstream & buffer) override;
        MessageTypes getType() const override;
};


}}}}} // End namespace

