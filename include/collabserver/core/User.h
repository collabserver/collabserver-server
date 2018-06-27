#pragma once

#include <cassert>

#include "Room.h"

namespace collab {


/**
 * \brief
 * User registered in CollabServer working instance.
 *
 * \author  Constantin Masson
 * \date    May 2018
 */
class User {
    private:
        static int  idcounter;
        const int   _id;
        Room*       _currentRoom = nullptr;

    public:
        User();

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


