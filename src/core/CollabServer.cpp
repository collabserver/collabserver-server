#include "collabserver/core/CollabServer.h"

#include <utility>  // std::pair

namespace collabserver {

CollabServer::CollabServer(Broadcaster& carrot) : _broadcaster(carrot) {
    // I choose arbitrary numbers. Reserves x users and rooms.
    _users.reserve(20);
    _rooms.reserve(10);
}

CollabServer::~CollabServer() {
    for (auto& user_it : _users) {
        this->deleteUser(user_it.second.getUserID());
    }
    for (auto& room_it : _rooms) {
        this->deleteRoom(room_it.second.getRoomID());
    }
}

// -----------------------------------------------------------------------------
// Users
// -----------------------------------------------------------------------------

const User* CollabServer::createNewUser() {
    const unsigned int id = User::USER_ID_COUNTER + 1;
    auto it = _users.insert(std::make_pair(id, User()));
    return &(it.first->second);
}

bool CollabServer::deleteUser(const unsigned int id) {
    auto it = _users.find(id);
    if (it == _users.end()) {
        return false;
    }
    User& user = it->second;
    Room* room = user.getRoom();
    if (room != nullptr) {
        bool success = room->removeUser(user);
        if (!success) {
            return false;
        }
    }
    return _users.erase(id) == 1;
}

bool CollabServer::isUserInRoom(const unsigned int userID, const unsigned int roomID) const {
    const User* user = this->findUser(userID);
    const Room* room = this->findRoom(roomID);
    if (user == nullptr || room == nullptr || user->getRoom() == nullptr) {
        return false;
    }
    return user->getRoom()->getRoomID() == roomID;
}

bool CollabServer::isUserInAnyRoom(const unsigned int userID) const {
    const User* user = this->findUser(userID);
    if (user == nullptr) {
        return false;
    }
    return user->getRoom() != nullptr;
}

bool CollabServer::userJoinRoom(const unsigned int userID, const unsigned int roomID) {
    User* user = this->findUser(userID);
    Room* room = this->findRoom(roomID);
    if (user == nullptr || room == nullptr) {
        return false;
    }
    return room->addUser(*user);
}

bool CollabServer::userLeaveCurrentRoom(const unsigned int userID) {
    User* user = this->findUser(userID);
    if (user == nullptr || user->getRoom() == nullptr) {
        return false;
    }
    return user->getRoom()->removeUser(*user);
}

bool CollabServer::isUserUgly(const unsigned int userID) {
    User* user = this->findUser(userID);
    return (user != nullptr) ? user->isUserUgly() : true;
}

const User* CollabServer::findUser(const unsigned int id) const {
    auto user_it = _users.find(id);
    if (user_it == _users.end()) {
        return nullptr;
    }
    return &(user_it->second);
}

User* CollabServer::findUser(const unsigned int id) {
    auto user_it = _users.find(id);
    if (user_it == _users.end()) {
        return nullptr;
    }
    return &(user_it->second);
}

// -----------------------------------------------------------------------------
// Rooms
// -----------------------------------------------------------------------------

const Room* CollabServer::createNewRoom() {
    const unsigned int id = Room::ROOM_ID_COUNTER + 1;
    auto it = _rooms.emplace(std::make_pair(id, Room(_broadcaster)));
    return &(it.first->second);
}

bool CollabServer::deleteRoom(const unsigned int id) {
    auto it = _rooms.find(id);
    if (it == _rooms.end()) {
        return false;
    }

    Room& room = it->second;
    if (!room.isEmpty()) {
        return false;
    }

    return _rooms.erase(id) == 1;
}

bool CollabServer::commitOperationInRoom(const OperationInfo& op, const unsigned int id) {
    Room* room = this->findRoom(id);
    if (room == nullptr) {
        return false;
    }
    return room->commitOperation(op);
}

const Room* CollabServer::findRoom(const unsigned int id) const {
    auto room_it = _rooms.find(id);
    if (room_it == _rooms.end()) {
        return nullptr;
    }
    return &(room_it->second);
}

Room* CollabServer::findRoom(const unsigned int id) {
    auto room_it = _rooms.find(id);
    if (room_it == _rooms.end()) {
        return nullptr;
    }
    return &(room_it->second);
}

}  // namespace collabserver
