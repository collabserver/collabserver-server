#pragma once

#include "collabdata/custom/Operation.h"

#include "OperationInfo.h"

namespace collab {


/**
 * \brief
 * Defines the set of callback functions the CollabServer core may call.
 *
 * This may be used by the network component for instance, to broadcast events
 * from CollabServer. (Such as operation in room etc).
 */
class Broadcaster {

    protected:
        Broadcaster() = default;


    // -------------------------------------------------------------------------
    // Callback methods interface
    // -------------------------------------------------------------------------

    public:
        virtual void sendRoomUserOperation(const OperationInfo& op,
                                           const int roomID,
                                           const int userID) = 0;
};


} // End namespace


