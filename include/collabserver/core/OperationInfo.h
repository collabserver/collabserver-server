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
        int opID;                   // Operation's unique ID
        int opTypeID;               // Operation's type
        int userID;                 // User that made this operation
        int roomID;                 // Room where operation is done

    public:
        OperationInfo() = default;
        OperationInfo(const OperationInfo& info) {
            opID        = info.opID;
            opTypeID    = info.opTypeID;
            userID      = info.userID;
            roomID      = info.roomID;
            buffer.str(info.buffer.str());
        }
};


} // End namespace


