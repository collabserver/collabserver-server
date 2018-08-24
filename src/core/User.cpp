#include "collabserver/core/User.h"

namespace collab {


int User::idcounter = 0;

User::User() : _id(++idcounter) {
    // Nothing else to do (Or nothing else matter)
}

bool User::joinRoom(Room& room) {
    if(_currentRoom != nullptr) {
        return false;
    }
    bool added = room.addUser(_id);
    if(added) {
        _currentRoom = &room;
        return true;
    }
    return false;
}

bool User::leaveCurrentRoom() {
    if(_currentRoom == nullptr) {
        return false;
    }
    bool removed = _currentRoom->removeUser(_id);
    if(removed) {
        _currentRoom = nullptr;
        return true;
    }
    return false;
}


} // End namespace


