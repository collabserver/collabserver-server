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
 *
 * \note
 * Note about IDs:
 * ID removes coupling between broadcaster and core business components.
 * For instance, ID may be the user ID in business side, and a simple
 * ID linked with a socket in network side.
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
         * Send operation to the user.
         *
         * \param op        Operation to send.
         * \param userID    User recipient.
         */
        virtual void sendOperationToUser(const OperationInfo& op,
                                         const int userID) = 0;

        /**
         * Send operation to the storage.
         *
         * \param op        Operation to send.
         * \param storageID ID where to send operation.
         */
        virtual void sendOperationToStorage(const OperationInfo& op,
                                            const int storageID) = 0;
};


} // End namespace

