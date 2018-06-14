#pragma once

#include <unordered_map>

#include "collabdata/utils/CollabData.h"
#include "collabdata/utils/Operation.h"

#include "User.h"
#include "Connector.h"

namespace collab {


/**
 * TODO Documentation
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
class Room {
    private:
        std::unordered_map<int, User>   _users;
        std::vector<Operation>          _operations;
        CollabData*                     _data = nullptr;
        Connector*                      _connector = nullptr;

    public:
        Room() = default;
        ~Room() = default;

    public:
        bool addUser(const int id);
        bool removeUser(const int id);
        int getNbUsers() const;
        void receiveOperation(const Operation& op);
};


} // End namespace

