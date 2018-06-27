#pragma once

#include <unordered_set>
#include <sstream>

#include "collabdata/custom/CollabData.h"
#include "collabdata/custom/Operation.h"

#include "Connector.h"
#include "DataFactory.h"

namespace collab {


/**
 * Information about an operation.
 */
struct OperationInfo {
    std::stringstream buffer;   // Operation in serialized form
    int userID;                 // User that made this operation
    int typeID;                 // Operation's type
    int opID;                   // Operation's unique ID
};


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

        std::unordered_set<int>         _users;
        std::vector<OperationInfo>      _operations;
        Connector&                      _connector;
        CollabData*                     _data = nullptr;

        int                             _currentHeadOperationID = 0;
        const int                       _roomID;


    // -------------------------------------------------------------------------
    // Setup / Init
    // -------------------------------------------------------------------------

    public:
        Room(const DataAvailable dataID, Connector& connector);
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

        /**
         * TODO blablabla
         */
        void sendOperation(const Operation& op, const int userToID) const;
};


} // End namespace


