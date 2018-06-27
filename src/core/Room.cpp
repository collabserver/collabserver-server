#include "collabserver/core/Room.h"

#include <utility> // std::pair
#include <cassert>

namespace collab {

int Room::idcounter = 0;

Room::Room(const CollabDataAvailable dataID, Connector& connector)
  : _connector(connector), _roomID(++idcounter) {
    _data = CollabDataFactory::newCollabDataByID(dataID);
    assert(_data != nullptr);
    if(_data == nullptr) {
        _data = CollabDataFactory::newCollabDataByID(
                    CollabDataAvailable::DEFAULT_DATA);
    }

    _users.reserve(15); // Pre-allocate for 15 users
    _operations.reserve(100); // Pre-allocate for 100 operations
}

Room::~Room() {
    CollabDataFactory::releaseCollabData(_data);
}

bool Room::addUser(const int id) {
    auto result = _users.emplace(id);
    return result.second;
}

bool Room::removeUser(const int id) {
    int removed = _users.erase(id);
    return (removed == 1);
}

bool Room::isEmpty() const {
    return _users.size() == 0;
}

int Room::getNbUsers() const {
    return _users.size();
}

bool Room::receiveOperation(OperationInfo& op, const int userFromID) {
    assert(_data != nullptr);

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
    info.opID   = _currentHeadOperationID;

    _currentHeadOperationID++;

    float load = _operations.size() / _operations.capacity();
    if(load > 0.90) {
        _operations.reserve(_operations.size() + 20); // 20 is arbitrary
    }

    return true;
}

void Room::sendOperation(const Operation& op, const int userToID) const {
    _connector.sendRoomUserOperation(op, _roomID, userToID);
}


} // End namespace


