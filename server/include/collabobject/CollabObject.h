#pragma once

#include "History.h"


namespace collab {


class CollabObject {
    protected:
        History m_history;

    protected:
        CollabObject() = default;
        virtual ~CollabObject() = default;
};


} // End namespace
