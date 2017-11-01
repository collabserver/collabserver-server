#pragma once

//class History;
#include "History.h"


namespace collab {
namespace collabobject {


class CollabObject {
    protected:
        History m_history;

    protected:
        CollabObject() = default;
        virtual ~CollabObject() = default;
};


} // End namepsace
} // End namespace
