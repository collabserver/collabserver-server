#pragma once



namespace collab {


class CreateMsgSerializer {
    public:
        CreateMsgData unserialize(const void* data);
        bool serialize(const void* data);
};


} // End namespace
