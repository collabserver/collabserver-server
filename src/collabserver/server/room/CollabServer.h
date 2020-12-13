#pragma once

#include <cstddef>  // For std::size_t
#include <unordered_map>

#include "Broadcaster.h"
#include "Room.h"
#include "User.h"

namespace collabserver {

/**
 * \brief
 * The famous collaborative server component where all rooms are located.
 *
 * This is the entry point to deal with 'room' components and features
 * such as adding, removing user or room.
 */
class CollabServer {
   private:
    std::unordered_map<unsigned int, User> _users;
    std::unordered_map<unsigned int, Room> _rooms;
    Broadcaster& _broadcaster;

   public:
    /**
     * Create a new CollabServer component.
     * Broadcaster is used for any callback methods CollabServer may
     * emit whenever a method is applied.
     *
     * \param broadcaster Concret broadcaster to use with this CollabServer.
     */
    CollabServer(Broadcaster& broadcaster);

    /**
     * Delete all rooms and all users.
     */
    ~CollabServer();

    // -------------------------------------------------------------------------
    // Users management
    // -------------------------------------------------------------------------

   public:
    /**
     * Create a new user in the CollabServer.
     *
     * \return Pointer to created user or nullptr if error.
     */
    const User* createNewUser();

    /**
     * Remove a created user from the current CollabServer.
     * If no user for this ID, returns false.
     * If user is in a room, he is removed from the room.
     *
     * \param id ID of the user to remove.
     * \return True if successfully removed, otherwise, return false.
     */
    bool deleteUser(const unsigned int id);

    /**
     * Returns the current number of users on this CollabServer.
     *
     * \return Number of users.
     */
    std::size_t getNbUsers() const { return _users.size(); }

    /**
     * Check whether user is in CollabServer.
     *
     * \param id The user ID to search for.
     * \return True if is in CollabServer, otherwise, return false.
     */
    bool hasUser(const unsigned int id) const { return _users.count(id) == 1; }

    /**
     * Check whether the given user (By ID) is in the room (By ID).
     *
     * \param userID ID of the user.
     * \param roomID ID of the room.
     * \return True if user is in room, otherwise, returns false.
     */
    bool isUserInRoom(const unsigned int userID, const unsigned int roomID) const;

    /**
     * Check whether this user is in a room.
     *
     * \return True if user is currently in a room, otherwise, return false.
     */
    bool isUserInAnyRoom(const unsigned int userID) const;

    /**
     * Try to add a user to a room (Using IDs).
     * User and room must exist.
     * User must not be in room yet.
     *
     * \param userID ID of the user to add in the room.
     * \param roomID ID of the room where to place user.
     * \return True if successfully added in room, otherwise, return false.
     */
    bool userJoinRoom(const unsigned int userID, const unsigned int roomID);

    /**
     * Tries to remove a user from its current room.
     * Returns false if user was not in a room yet.
     *
     * \return True if successfully left, otherwise, return false.
     */
    bool userLeaveCurrentRoom(const unsigned int userID);

    /**
     * Check whether this user is ugly.
     * (Yeah, this is the super useful method.)
     *
     * \param id ID of the user to check.
     * \return True if is ugly (According to server).
     */
    bool isUserUgly(const unsigned int userID);

    /**
     * Get user by its ID.
     *
     * \param id ID of the user to find.
     * \return Pointer to the user data or nullptr if no user for this id.
     */
    const User* findUser(const unsigned int id) const;

   private:
    // DevNote: user should not be able to modify User directly but only
    // through CollabServer, therefore this method is only for internal
    // use and should be private.

    /**
     * \copydoc CollabServer::findUser
     */
    User* findUser(const unsigned int id);

    // -------------------------------------------------------------------------
    // Rooms
    // -------------------------------------------------------------------------

   public:
    /**
     * Create a new room of collaboration in the CollabServer.
     *
     * \return Pointer to the newly created room or nullptr if error.
     */
    const Room* createNewRoom();

    /**
     * Remove a room.
     * The room must be empty.
     *
     * \param id The unique ID of the room.
     * \return True if successfully deleted, otherwise, return false.
     */
    bool deleteRoom(const unsigned int id);

    /**
     * Commit an operation to the given room.
     * Do nothing if invalid data.
     *
     * \param op Reference to the operation to commit.
     * \param roomID ID of the room where to commit operation.
     * \return True if successfully committed, otherwise, return false.
     */
    bool commitOperationInRoom(const OperationInfo& op, const unsigned int roomID);

    /**
     * Returns the current number of rooms in the CollabServer
     *
     * \return Number of rooms.
     */
    std::size_t getNbRooms() const { return _rooms.size(); }

    /**
     * Check whether room is in CollabServer.
     *
     * \param id The room ID to search for.
     * \return True if is in CollabServer, otherwise, return false.
     */
    bool hasRoom(const unsigned int id) const { return _rooms.count(id) == 1; }

    /**
     * Get room from its ID.
     *
     * \param id ID of the room to find.
     * \return Pointer to the room data or nullptr if no room for this id.
     */
    const Room* findRoom(const unsigned int id) const;

   private:
    // DevNote: user should not be able to modify room directly but only
    // through CollabServer, therefore this method is only for internal
    // use and should be private.

    /**
     * \copydoc CollabServer::findRoom
     */
    Room* findRoom(const unsigned int id);
};

}  // namespace collabserver
