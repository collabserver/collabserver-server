#pragma once


namespace collab {


template<class E>
class Route {
    private:
        int messageType;
        AbsMessageFactory factory;
        E* eventHandler;
};


} // End namespace
