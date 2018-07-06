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
        Broadcaster(const Broadcaster& other) = default;
        Broadcaster& operator=(const Broadcaster& other) = default;
    public:
        virtual ~Broadcaster() = default;


    // -------------------------------------------------------------------------
    // Callback methods interface
    // -------------------------------------------------------------------------

    public:

        /**
         * Send operation to the destination.
         *
         * ID removes coupling between broadcaster and core business components.
         * For instance, this may be the user ID in business side, and a simple
         * ID linked with a socket in network side.
         *
         * \param op    Operation to send.
         * \param dest  ID where to send operation.
         */
        virtual void sendOperation(const OperationInfo& op, const int dest) = 0;
};


} // End namespace


