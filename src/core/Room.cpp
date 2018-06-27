#include "collabserver/core/Room.h"

#include <utility> // std::pair
#include <cassert>

#include "collabserver/core/User.h"

namespace collab {


bool Room::addUser(const int id) {
    auto result = _users.emplace(std::make_pair(id, User{id}));
    return result.second;
}

bool Room::removeUser(const int id) {
    int removed = _users.erase(id);
    return removed == 1;
}

int Room::getNbUsers() const {
    return _users.size();
}

bool Room::registerData(CollabData& data) {
    if(_data != nullptr) {
        return false;
    }
    _data = &data;
    return true;
}

bool Room::unregisterData() {
    if(_data == nullptr) {
        return false;
    }
    _data = nullptr;
    return true;
}

bool Room::receiveOperation(OperationInfo& op) {
    if(_data == nullptr) {
        return false;
    }

    bool isApplied = _data->receiveOperation(op.typeID, op.buffer);
    if(!isApplied) {
        return false;
    }
    assert(_operations.capacity() > 0); // If false, you forgot to reserve
    OperationInfo info;
    info.buffer.str(op.buffer.str()); // Copy content
    info.typeID = op.typeID;
    info.userID = op.userID;
    info.opID = _currentHeadOperationID;
    _currentHeadOperationID++;

    float load = _operations.size() / _operations.capacity();
    if(load > 0.90) {
        _operations.reserve(_operations.size() + 20); // 20 is arbitrary
    }

    return true;
}

void Room::sendOperation(const Operation& op, const int userID) {
    _connector->sendUserOperation(op, userID);
}


} // End namespace


