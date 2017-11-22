#pragma once


namespace collab {


class Router {
    private:
        JsonSerializer serializer;

    public:
        void receiveMessage(char* msg);
};


} // End namespace
