#pragma once

namespace collab {


class Message {
    protected:
        Message() = default;
    public:
        virtual ~Message() = default;

    /*
    protected:
        template <class T> bool serialize(T & stream);

    public:
        virtual bool serialize();
    */
};


} // End namespace
