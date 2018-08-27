#include "collabserver/core/CollabServer.h"

#include <utility> // std::pair

namespace collab {


CollabServer::CollabServer(Broadcaster& carrot) : _broadcaster(carrot) {
    // I choose arbitrary numbers. Reserves x users and rooms.
    _users.reserve(20);
    _rooms.reserve(10);
}

CollabServer::~CollabServer() {
    for(auto& user_it : _users) {
        this->deleteUser(user_it.second.getUserID());
    }
    for(auto& room_it : _rooms) {
        this->deleteRoom(room_it.second.getRoomID());
    }
}


// -----------------------------------------------------------------------------
// Users
// -----------------------------------------------------------------------------

int CollabServer::createNewUser() {
    User coco; // Tmp copy but that's ok
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
    return _users.erase(id) == 1;
}

int CollabServer::getNbUsers() const {
    return _users.size();
}

bool CollabServer::hasUser(const int id) const {
    return _users.count(id) == 1;
}

User* CollabServer::findUser(const int id) {
    auto user_it = _users.find(id);
    if(user_it == _users.end()) {
        return nullptr;
    }
    return &(user_it->second);
}


// -----------------------------------------------------------------------------
// Rooms
// -----------------------------------------------------------------------------

int CollabServer::createNewRoom() {
    const int id = Room::getNextExpectedRoomID();
    _rooms.emplace(std::make_pair(id, Room(_broadcaster)));
    return id;
}

bool CollabServer::deleteRoom(const int id) {
    auto it = _rooms.find(id);
    if(it == _rooms.end()) {
        return false;
    }

    Room& room = it->second;
    if(!room.isEmpty()) {
        return false;
    }

    return _rooms.erase(id) == 1;
}

int CollabServer::getNbRooms() const {
    return _rooms.size();
}

bool CollabServer::hasRoom(const int id) const {
    return _rooms.count(id) == 1;
}

Room* CollabServer::findRoom(const int id) {
    auto room_it = _rooms.find(id);
    if(room_it == _rooms.end()) {
        return nullptr;
    }
    return &(room_it->second);
}


} // End namespace


