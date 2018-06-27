#pragma once

#include "collabdata/custom/Operation.h"

namespace collab {


/**
 * \brief
 * Connector interface.
 *
 * \todo
 * Documentation to add.
 *
 *
 * \author  Constantin Masson
 * \date    June 2018
 */
class Connector {
    // -------------------------------------------------------------------------
    // Callable methods interface
    // -------------------------------------------------------------------------

    public:
        virtual void addUserInRoom(const int userID, const int roomID) = 0;
        virtual void removeUserInRoom(const int userID, const int roomID) = 0;


    // -------------------------------------------------------------------------
    // Callback methods interface
    // -------------------------------------------------------------------------

    public:
        virtual void sendUserOperation(const Operation& op, const int userID) = 0;
};


} // End namespace


