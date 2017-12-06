#pragma once

#include "Mutation.h"
#include <stack>


namespace collab {


class History {
    private:
        std::stack<Mutation> m_mutations;

    public:
        History() = default;
        ~History() = default;

    public:
        void clear();
};


} // End namespace
