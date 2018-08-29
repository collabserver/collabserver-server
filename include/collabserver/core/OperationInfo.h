#pragma once

#include <sstream>

#include "collabdata/custom/Operation.h"

namespace collab {


/**
 * \brief
 * Information about an operation.
 */
class OperationInfo {
    public:
        std::stringstream buffer;   // Operation in serialized form
        int userID;                 // User that made this operation
        int roomID;                 // Room where operation is done

    public:
        OperationInfo() = default;
        OperationInfo(const OperationInfo& info) {
            buffer.str(info.buffer.str());
            userID      = info.userID;
            roomID      = info.roomID;
        }
};


} // End namespace


