#pragma once

#include "OperationInfo.h"

namespace collabserver {

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
     * \param op    Operation to send.
     * \param id    ID of the recipient user.
     */
    virtual void sendOperationToUser(const OperationInfo& op, unsigned int id) = 0;

    /**
     * Broadcast the operation to all users in a room.
     *
     * \param op    Operation to send.
     * \param id    Room ID where to send operation.
     */
    virtual void broadcastOperationToRoom(const OperationInfo& op, unsigned int id) = 0;
};

}  // namespace collabserver
