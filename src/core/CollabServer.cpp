#include "collabserver/core/CollabServer.h"

#include "collabcommon/utils/Log.h"

namespace collab {


// -----------------------------------------------------------------------------
// Users
// -----------------------------------------------------------------------------

int CollabServer::createNewUser() {
    // There is a copy but that's ok
    User coco;
    _users.insert(std::make_pair(coco.getUserID(), coco));
    return coco.getUserID();
}

bool CollabServer::deleteUser(const int id) {
    auto it = _users.find(id);
    if(it == _users.end()) {
        return false;
    }
    User& user = it->second;
    bool success = user.leaveCurrentRoom();
    if(!success) {
        return false;
    }
    return (_users.erase(id) == 1);
}

int CollabServer::getNbUsers() const {
    return _users.size();
}


// -----------------------------------------------------------------------------
// Rooms
// -----------------------------------------------------------------------------

int CollabServer::createNewRoom() {
    /*
    Room room;
    _rooms.insert(std::make_pair(room.getRoomID(), room));
    return room.getRoomID();
    */
}

bool CollabServer::deleteRoom(const int id) {
}

int CollabServer::getNbRooms() const {
    return _rooms.size();
}


} // End namespace


