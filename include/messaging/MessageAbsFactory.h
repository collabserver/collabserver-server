#pragma once


namespace collab {

class Message;


class MessageAbsFactory {
    protected:
        MessageAbsFactory() = default;
        virtual ~MessageAbsFactory() = default;

    public:
        virtual Message* newMessage(const int type) const = 0;
        virtual int getMessageTypeCounter() const = 0;
};


} // End namespace
