#pragma once

#include "Route.h"

#include <unordered_map>
#include <cstring> // size_t

namespace collab {


class Router {
    public:
        Router();

    private:
        std::unordered_map<int, Route> m_lookupRoutes;

    public:
        void processMessage(const char* msg, const size_t size) const;
        void addRoute(const int messageType, const Event* event);
};


} // End namespace
