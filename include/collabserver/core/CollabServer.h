#pragma once

#include <unordered_map>
#include <utility>

#include "User.h"

namespace collab {


/**
 * \brief
 * The famous collaborative server component where all rooms are located.
 *
 *
 * \author  Constantin Masson
 * \date    Jun 2018
 */
class CollabServer {
    private:
        std::unordered_map<int, User>   _users;
        std::unordered_map<int, Room>   _rooms;


    // -------------------------------------------------------------------------
    // Users
    // -------------------------------------------------------------------------

    public:

        /**
         * Create a new user in the CollabServer.
         * Return the associated ID for this user.
         *
         * \return ID of the newly created user.
         */
        int createNewUser();

        /**
         * Remove a created user from the current CollabServer.
         * If no user for this ID, returns false.
         *
         * \param id ID of the user to remove.
         * \return True if successfully removed, otherwise, return false.
         */
        bool deleteUser(const int id);

        /**
         * Returns the current number of users on this CollabServer.
         *
         * \return Number of users.
         */
        int getNbUsers() const;


    // -------------------------------------------------------------------------
    // Rooms
    // -------------------------------------------------------------------------

    public:

        /**
         * Create a new room.
         *
         * \return ID of the created room.
         */
        int createNewRoom();

        /**
         * Remove a room. The room must be empty.
         *
         * \param id The unique ID of the room.
         * \return True if successfully deleted, otherwise, return false.
         */
        bool deleteRoom(const int id);

        /**
         * Returns the current number of rooms in the CollabServer
         *
         * \return Number of rooms.
         */
        int getNbRooms() const;
};


} // End namespace


