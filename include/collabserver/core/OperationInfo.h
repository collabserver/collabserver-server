#pragma once

#include <string>

#include "collabdata/custom/Operation.h"

namespace collab {


/**
 * \brief
 * Information about an operation.
 */
class OperationInfo {
    public:
        std::string buffer;     // Operation in serialized form
        int roomID;             // Room where operation is done
        int userID;             // User that made this operation
        int opTypeID;           // ID of the operation type

    public:
        OperationInfo() = default;
        OperationInfo(const OperationInfo& info) {
            roomID      = info.roomID;
            userID      = info.userID;
            opTypeID    = info.opTypeID;
            buffer      = info.buffer;
        }
};


} // End namespace


