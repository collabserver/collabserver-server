#pragma once

#include <cassert>

#include "Room.h"

namespace collab {


/**
 * \brief
 * Working user session in CollabServer instance.
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
class UserSession {
    private:
        static int  idcounter;
        const int   _id;
        Room*       _currentRoom = nullptr;

    public:
        UserSession();

    public:
        bool joinRoom(Room& room);
        bool leaveCurrentRoom();

    public:
        int getID() const {
            return _id;
        }

        bool isInRoom() {
            return _currentRoom != nullptr;
        }
};


} // End namespace


