#pragma once

#include <string>

namespace collabserver {

/**
 * \brief
 * Information about an operation.
 */
class OperationInfo {
   public:
    std::string buffer;     // Operation in serialized form
    unsigned int roomID;    // Room where operation is done
    unsigned int userID;    // User that made this operation
    unsigned int opTypeID;  // ID of the operation type

   public:
    OperationInfo() = default;
    OperationInfo(const OperationInfo& info) {
        roomID = info.roomID;
        userID = info.userID;
        opTypeID = info.opTypeID;
        buffer = info.buffer;
    }
};

}  // namespace collabserver
