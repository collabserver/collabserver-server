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
        int userID;                 // User that made this operation
        int typeID;                 // Operation's type
        int roomID;                 // Room where operation is done

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


