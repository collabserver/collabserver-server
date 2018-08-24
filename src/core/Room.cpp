#include "collabserver/core/Room.h"

#include <cassert>
#include <utility> // std::pair

namespace collab {


int Room::idcounter = 0;


Room::Room(Broadcaster& broadcaster) : _broadcaster(broadcaster) {
    _id = ++idcounter;
    _users.reserve(15); // Reserve values are totally arbitrary here.
    _operations.reserve(100);
}


// -----------------------------------------------------------------------------
// Users management
// -----------------------------------------------------------------------------

bool Room::addUser(const int id) {
    auto result = _users.emplace(id);
    return result.second;
}

bool Room::removeUser(const int id) {
    return _users.erase(id) == 1;
}

bool Room::hasUser(const int id) const {
    return _users.find(id) != _users.end();
}

bool Room::isEmpty() const {
    return _users.empty();
}

int Room::getNbUsers() const {
    return _users.size();
}


// -----------------------------------------------------------------------------
// Operations
// -----------------------------------------------------------------------------

bool Room::commitOperation(const OperationInfo& op) {
    if(op.roomID != _id || !this->hasUser(op.userID)) {
        assert(false); // It's your fault ugly rabbit!
        return false;
    }

    OperationInfo newOP = op;
    newOP.opID = _operationHeadID;
    _operationHeadID++;

    assert(_operations.capacity() > 0); // If false, you forgot to reserve
    float load = _operations.size() / _operations.capacity();
    if(load > 0.90) {
        _operations.reserve(_operations.size() + 20); // 20 is arbitrary
    }
    _operations.emplace_back(newOP);

    // TODO: change this with a broadcast
    for(const int userID : _users) {
        if(op.userID == userID) {
            continue;
        }
        _broadcaster.sendOperationToUser(newOP, userID);
    }

    return true;
}


} // End namespace


