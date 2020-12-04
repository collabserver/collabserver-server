#pragma once

#include <cstddef>  // std::size_t
#include <unordered_set>
#include <vector>

#include "Broadcaster.h"
#include "OperationInfo.h"
#include "User.h"

namespace collabserver {

/**
 * \brief
 * Room of collaboration.
 */
class Room {
   public:
    static unsigned int ROOM_ID_COUNTER;

   private:
    const unsigned int _id;
    std::vector<OperationInfo> _operations;
    std::unordered_set<unsigned int> _users;
    Broadcaster& _broadcaster;

    // -------------------------------------------------------------------------
    // Setup / Init
    // -------------------------------------------------------------------------

   public:
    Room(Broadcaster& broadcaster);

    // -------------------------------------------------------------------------
    // Users management
    // -------------------------------------------------------------------------

   public:
    /**
     * Add user in this room.
     * If user is already in a room, do nothing and return false.
     * This also set the user room.
     *
     * \param user Reference to the user to add in room.
     * \return True if successfully added, otherwise, return false.
     */
    bool addUser(User& user);

    /**
     * Remove user from this room.
     * Do nothing if user was not in this room and return false.
     * This also set the user room.
     *
     * \param user Reference to the user to remove from the room.
     * \return True if successfully removed, otherwise, return false.
     */
    bool removeUser(User& user);

    // -------------------------------------------------------------------------
    // Operations
    // -------------------------------------------------------------------------

   public:
    /**
     * Commit an operation in this room.
     * Uses the information given inside OperationInfo.
     * Check validity (Room, user in room etc).
     * Broadcast this operation to all registered users.
     *
     * \param op    The new operation to commit in the room.
     * \return True if successfully commited, otherwise, return false.
     */
    bool commitOperation(const OperationInfo& op);

    // -------------------------------------------------------------------------
    // Various
    // -------------------------------------------------------------------------

   public:
    /**
     * Check whether the given user (By ID) is in room.
     *
     * \param id User id.
     * \return True if user is in this room, otherwise, return false.
     */
    bool hasUser(const unsigned int id) const;

    /**
     * Check whether the given user (By reference) is in room.
     *
     * \param user Reference to the user to check.
     * \return True if user is in this room, otherwise, return false.
     */
    bool hasUser(const User& user) const;

    /**
     * Check whether this room is empty.
     *
     * \return True if empty, otherwise, return false.
     */
    bool isEmpty() const { return _users.empty(); }

    /**
     * Returns number of users in this room.
     *
     * \param Number of users.
     */
    std::size_t getNbUsers() const { return _users.size(); }

    /**
     * Get room ID. (Unique in the server instance).
     *
     * \return Room ID.
     */
    unsigned int getRoomID() const { return _id; }
};

}  // namespace collabserver
