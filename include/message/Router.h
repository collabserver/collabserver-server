#pragma once

#include "Route.h"

#include <unordered_map>
#include <cstring> // size_t

namespace collab {


class Router {
    public:
        Router();

    private:
        std::unordered_map<int, int> m_lookupRoutes;

    public:
        void processMessage(const char* msg, const size_t size) const;
};


} // End namespace
