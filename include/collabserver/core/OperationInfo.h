#pragma once

#include <sstream>

#include "collabdata/custom/Operation.h"

namespace collab {


/**
 * Information about an operation.
 */
class OperationInfo {
    public:
        std::stringstream buffer;   // Operation in serialized form
        int userID;                 // User that made this operation
        int typeID;                 // Operation's type
        int opID;                   // Operation's unique ID

    public:
        OperationInfo() = default;
        OperationInfo(const OperationInfo& info) {
            userID = info.userID;
            typeID = info.typeID;
            opID   = info.opID;
            buffer.str(info.buffer.str());
        }
};


} // End namespace


