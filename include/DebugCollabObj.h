#pragma once

#include "CollabObject.h"


namespace collab {


/**
 * A simple CollabObject implementation for debug and test purpose.
 */
class DebugCollabObject : public CollabObject {
    private:
        std::vector m_vector;

    public:
        DebugCollabObject() = default;
};

} // End namespace
