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
        int userID;             // User that made this operation
        int roomID;             // Room where operation is done

    public:
        OperationInfo() = default;
        OperationInfo(const OperationInfo& info) {
            buffer  = info.buffer;
            userID  = info.userID;
            roomID  = info.roomID;
        }
};


} // End namespace


