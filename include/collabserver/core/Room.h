#pragma once

#include <unordered_map>
#include <sstream>

#include "collabdata/utils/CollabData.h"
#include "collabdata/utils/Operation.h"

#include "User.h"
#include "Connector.h"

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
 *
 * TODO Documentation
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
class Room {
    private:
        std::unordered_map<int, User>   _users;
        std::vector<OperationInfo>      _operations;
        CollabData*                     _data = nullptr;
        Connector*                      _connector = nullptr;
        int                             _currentHeadOperationID = 0;

    public:
        Room() {
            _users.reserve(15); // Pre-allocate for 15 users
            _operations.reserve(100); // Pre-allocate for 100 operations
        }

    public:
        bool addUser(const int id);
        bool removeUser(const int id);
        int getNbUsers() const;

        bool registerData(CollabData& data);
        bool unregisterData();

        bool receiveOperation(OperationInfo& op);
};


} // End namespace


