#pragma once

#include <unordered_map>

#include "Broadcaster.h"
#include "Room.h"
#include "User.h"

namespace collab {


/**
 * \brief
 * The famous collaborative server component where all rooms are located.
 */
class CollabServer {
    private:
        std::unordered_map<int, User>   _users;
        std::unordered_map<int, Room>   _rooms;
        Broadcaster&                    _broadcaster;

    public:
        /**
         * Create a new CollabServer component.
         * Broadcaster is used for any callback methods CollabServer may
         * emit whenever a method is applied.
         */
        CollabServer(Broadcaster& broadcaster);

        ~CollabServer();


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
         * If user is in a room, he is removed from the room.
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

        /**
         * Check whether user is in CollabServer.
         *
         * \param id The user ID to search for.
         * \return True if is in CollabServer, otherwise, return false.
         */
        bool hasUser(const int id) const;

        /**
         * Get user from its ID.
         *
         * \param id ID of the user to find.
         * \return Pointer to the user data or nullptr if no user for this id.
         */
        User* findUser(const int id);


    // -------------------------------------------------------------------------
    // Rooms
    // -------------------------------------------------------------------------

    public:

        /**
         * Create a new room of collaboration.
         * The room ID is required by users to join the room.
         *
         * \return ID of the created room.
         */
        int createNewRoom();

        /**
         * Remove a room.
         * The room must be empty.
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

        /**
         * Check whether room is in CollabServer.
         *
         * \param id The room ID to search for.
         * \return True if is in CollabServer, otherwise, return false.
         */
        bool hasRoom(const int id) const;

        /**
         * Get room from its ID.
         *
         * \param id ID of the room to find.
         * \return Pointer to the room data or nullptr if no room for this id.
         */
        Room* findRoom(const int id);
};


} // End namespace


