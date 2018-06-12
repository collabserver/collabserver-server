#pragma once

#include <unordered_map>

#include "User.h"

namespace collab {


/**
 * TODO Documentation
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
class Room {
    private:
        std::unordered_map<int, User> _users;

    public:
        Room() = default;
        ~Room() = default;

    public:
        bool addUser(const int id);
        bool removeUser(const int id);
        User& getUser(const int id);
        int getNbUsers() const;
};


} // End namespace

