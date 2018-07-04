#include "collabserver/core/Room.h"

#include <utility> // std::pair
#include <cassert>

namespace collab {

int Room::idcounter = 0;

Room::Room(const int dataID, Connector& connector)
        : _connector(connector), _id(++idcounter) {
    _data = DataFactory::newDataByID(dataID);

    assert(_data != nullptr);
    if(_data == nullptr) {
        _data = DataFactory::newDataByID(DataFactory::DataID::DEFAULT_DATA);
    }

    _users.reserve(15); // Pre-allocate for 15 users
    _operations.reserve(100); // Pre-allocate for 100 operations
}

Room::~Room() {
    DataFactory::releaseData(_data);
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
    _connector.sendRoomUserOperation(op, _id, userToID);
}


} // End namespace


