#include "collabserver/core/UserSession.h"

namespace collab {

int UserSession::idcounter = 0;

UserSession::UserSession() : _id (++idcounter) {
    // Nothing else to do (Or nothing else matter)
}

bool UserSession::joinRoom(Room& room) {
    if(_currentRoom == nullptr) {
        return false;
    }
    bool added = room.addUser(_id);
    if(added) {
        _currentRoom = &room;
        return true;
    }
    return false;
}

bool UserSession::leaveCurrentRoom() {
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


