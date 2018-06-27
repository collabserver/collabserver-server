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
    // Callback methods interface
    // -------------------------------------------------------------------------

    public:
        virtual void sendRoomUserOperation(const Operation& op,
                                           const int roomID,
                                           const int userID) = 0;
};


} // End namespace


