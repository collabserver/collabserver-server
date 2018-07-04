#pragma once

#include <unordered_set>

#include "collabdata/custom/CollabData.h"

#include "DataFactory.h"
#include "Broadcaster.h"
#include "OperationInfo.h"

namespace collab {


/**
 * \brief
 * Room of collaboration.
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
class Room {
    // -------------------------------------------------------------------------
    // Data
    // -------------------------------------------------------------------------
    private:
        static int idcounter;

        const int                       _id;
        CollabData*                     _data = nullptr;
        Broadcaster&                    _broadcaster;
        std::unordered_set<int>         _users;
        std::vector<OperationInfo>      _operations;
        int                             _currentHeadOperationID = 0;


    // -------------------------------------------------------------------------
    // Setup / Init
    // -------------------------------------------------------------------------

    public:
        Room(const int dataID, Broadcaster& broadcaster);
        ~Room();


    // -------------------------------------------------------------------------
    // Users management
    // -------------------------------------------------------------------------

    public:

        /**
         * Add user in this room.
         *
         * \warning
         * This simply add user id in the room set of IDs.
         * This DOES NOT update the user's current room.
         *
         * \param id ID of the user to add.
         */
        bool addUser(const int id);

        /**
         * Remove user from this room.
         *
         * \warning
         * This only removes user ID from room set of users.
         *
         * \param id ID of the user to remove.
         */
        bool removeUser(const int id);

        /**
         * Check whether user is in room.
         *
         * \param id User id.
         * \return True if user is in this room, otherwise, return false.
         */
        bool hasUser(const int id) const;

        /**
         * Check whether this room is empty.
         *
         * \return True if empty, otherwise, return false.
         */
        bool isEmpty() const;

        /**
         * Returns number of users in this room.
         *
         * \param Number of users.
         */
        int getNbUsers() const;


    // -------------------------------------------------------------------------
    // Operations
    // -------------------------------------------------------------------------

    public:

        /**
         * TODO blablabla
         */
        bool receiveOperation(OperationInfo& op, const int userFromID);


    // -------------------------------------------------------------------------
    // Verious
    // -------------------------------------------------------------------------

    public:

        int getRoomID() const {
            return _id;
        }

        static int getNextExpectedRoomID() {
            return Room::idcounter + 1;
        }
};


} // End namespace


