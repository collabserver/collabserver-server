#pragma once

#include <unordered_map>
#include <utility>

#include "User.h"

namespace collab {


/**
 * \brief
 * The famous collaborative instance component.
 *
 * CollabInstance has an ensemble of rooms that user may join, leave and,
 * collaborate.
 *
 * \author  Constantin Masson
 * \date    Jun 2018
 */
class CollabInstance {
    private:
        std::unordered_map<int, User>   _users;
        std::unordered_map<int, Room>   _rooms;

    public:

        /**
         * Create a new user in the collab instance.
         * Return the associated ID for this user.
         *
         * \return ID of the newly created user.
         */
        int createNewUser();

        /**
         * Remove a created user from the current collab instance.
         * If no user for this ID, returns false.
         *
         * \param id ID of the user to remove.
         * \return True if successfully removed, otherwise, return false.
         */
        bool deleteUser(const int id);

        /**
         * Returns the current number of users on this collab instance.
         *
         * \return Number of users.
         */
        int getNbUsers() const;
};


} // End namespace


