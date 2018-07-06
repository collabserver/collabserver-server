#pragma once

#include <unordered_set>

#include "collabdata/custom/CollabData.h"
#include "OperationInfo.h"

namespace collab {


class Broadcaster;
class Storage;
class StorageConfig;


/**
 * \brief
 * Room of collaboration.
 */
class Room {
    // -------------------------------------------------------------------------
    // Data
    // -------------------------------------------------------------------------
    private:
        static int idcounter;

        const int                       _id;
        CollabData*                     _data = nullptr;
        Storage*                        _storage = nullptr;
        Broadcaster&                    _broadcaster;
        std::unordered_set<int>         _users;
        std::vector<OperationInfo>      _operations;
        int                             _operationHeadID = 0;


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
    // Storage
    // -------------------------------------------------------------------------

    public:

        bool assignStorage(StorageConfig& config);
        bool hasStorage() const;


    // -------------------------------------------------------------------------
    // Operations
    // -------------------------------------------------------------------------

    public:

        /**
         * Commit an operation in this room.
         * Uses the information given inside OperationInfo.
         * Check validity (Room, user in room etc).
         *
         * \param op    The new operation to commit in the room.
         * \return True if successfully commited, otherwise, return false.
         */
        bool commitOperation(const OperationInfo& op);


    // -------------------------------------------------------------------------
    // Various
    // -------------------------------------------------------------------------

    public:

        int getRoomID() const;

        static int getNextExpectedRoomID();
};


} // End namespace


