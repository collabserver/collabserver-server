#include "collabserver/core/Room.h"

#include <cassert>
#include <utility> // std::pair

namespace collab {


unsigned int Room::ROOM_ID_COUNTER = 0;


Room::Room(Broadcaster& broadcaster) :
        _id(++ROOM_ID_COUNTER),
        _broadcaster(broadcaster) {
    _users.reserve(15); // Reserve values are totally arbitrary here.
    _operations.reserve(100);
}


// -----------------------------------------------------------------------------
// Users management
// -----------------------------------------------------------------------------

bool Room::addUser(User& user) {
    auto result = _users.emplace(user.getUserID());
    bool added = result.second;
    if(added) {
        user.setRoom(this);
        for(auto op : _operations) {
            _broadcaster.sendOperationToUser(op, user.getUserID());
        }
    }
    return added;
}

bool Room::removeUser(User& user) {
    bool removed = _users.erase(user.getUserID()) == 1;
    if(removed) {
        user.setRoom(nullptr);
    }
    return removed;
}

bool Room::hasUser(const unsigned int id) const {
    return _users.find(id) != _users.end();
}

bool Room::hasUser(const User& user) const {
    return _users.find(user.getUserID()) != _users.end();
}


// -----------------------------------------------------------------------------
// Operations
// -----------------------------------------------------------------------------

bool Room::commitOperation(const OperationInfo& op) {
    if(op.roomID != _id || !this->hasUser(op.userID)) {
        assert(false); // It's your fault ugly rabbit!
        return false;
    }

    _operations.emplace_back(op);

    assert(_operations.capacity() > 1); // If false, you forgot to reserve
    float load = _operations.size() / _operations.capacity();
    if(load > 0.90) {
        _operations.reserve(_operations.size() + 20); // 20 is arbitrary
    }

    _broadcaster.broadcastOperationToRoom(op, _id);

    return true;
}


} // End namespace


