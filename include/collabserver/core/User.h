#pragma once

namespace collab {

class Room;


/**
 * \brief
 * Describe a user registered in the CollabServer.
 *
 * A user has a unique ID for the running instance and may be placed in a room.
 * User may be in one room at the time.
 */
class User {
    public:
        static int  USER_ID_COUNTER;

    private:
        const int   _id;
        Room*       _room = nullptr;


    public:

        /**
         * Creates a new user and set its unique local ID.
         */
        User() : _id(++USER_ID_COUNTER) {}

        /**
         * Set pointer to the current room where user is collaborating.
         * Not check is done, this simply set, regardless the previous value.
         *
         * \param room Reference to the room to set.
         */
        void setRoom(Room* room) { _room = room; }

        /**
         * Get the room pointer where user is or nullptr if no room set.
         *
         * \return Pointer to the room or nullptr.
         */
        Room* getRoom() { return _room; }

        /**
         * \copydoc User::getRoom
         */
        const Room* getRoom() const { return _room; }

        /**
         * Returns ID of this user in the collab instance.
         *
         * \return User ID.
         */
        int getUserID() const { return _id; }

        /**
         * Good job! You just found my beautiful / stupid easter egg!
         * Check whether this user is actually Ugly!
         * This is probably one of the most important method in the whole code!
         *
         * \param id User id.
         * \return True if this user is ugly! (Burk!)
         */
        bool isUserUgly() const { return (_id % 42) != 0; }
};


} // End namespace


