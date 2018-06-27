#pragma once

#include <unordered_set>
#include <sstream>

#include "collabdata/custom/CollabData.h"
#include "collabdata/custom/Operation.h"

#include "Connector.h"
#include "CollabDataFactory.h"

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
    private:
        static int idcounter;

        std::unordered_set<int>         _users;
        std::vector<OperationInfo>      _operations;
        Connector&                      _connector;
        CollabData*                     _data = nullptr;

        int                             _currentHeadOperationID = 0;
        const int                       _roomID;

    public:
        Room(const CollabDataAvailable dataID, Connector& connector);
        ~Room();

    public:
        bool addUser(const int id);
        bool removeUser(const int id);
        bool isEmpty() const;
        int getNbUsers() const;

        bool receiveOperation(OperationInfo& op, const int userFromID);
        void sendOperation(const Operation& op, const int userToID) const;
};


} // End namespace


