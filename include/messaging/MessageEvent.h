#pragma once


namespace collab {

class Message;


class MessageEvent {
    protected:
        MessageEvent() = default;
    public:
        virtual ~MessageEvent() = default;

    public:
        virtual void run(Message& message) const = 0;
};


} // End namespace
