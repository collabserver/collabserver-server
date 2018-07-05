#pragma once

#include <cassert>

#include "Room.h"

namespace collab {


/**
 * \brief
 * User registered in current Collab instance.
 */
class User {
    private:
        static int  idcounter;
        const int   _id;
        Room*       _currentRoom = nullptr;

    public:

        /** Creates a new user and set its unique local ID. */
        User();

    public:

        /**
         * Join an existing room of collaboration.
         * Does nothing if user already in a room.
         * This also add user in the room
         *
         * \param room Reference to the room that user joins.
         * \param bool True if successfully joined, otherwise, return false.
         */
        bool joinRoom(Room& room);

        /**
         * Leave current room.
         * Does nothing if was not in a room already and return false.
         *
         * \return True if successfully left, otherwise, return false.
         */
        bool leaveCurrentRoom();

        /**
         * Returns ID of this user in the collab instance.
         *
         * \return User ID.
         */
        int getUserID() const;

        /**
         * Good job! You just found my beautiful / stupid easter egg!
         * Check whether this user is actually Ugly!
         * This is probably one of the most important method in the whole code!
         *
         * \param id User id.
         * \return True if this user is ugly! (Burk!)
         */
        bool isUserUgly() const;
};


} // End namespace


