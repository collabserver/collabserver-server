#include "collabserver/core/Room.h"

#include <utility> // std::pair
#include <cassert>

#include "collabserver/core/Broadcaster.h"
#include "collabserver/core/DataFactory.h"
#include "collabserver/core/Storage.h"

namespace collab {


int Room::idcounter = 0;


Room::Room(const int dataID, Broadcaster& broadcaster)
        : _id(++idcounter), _broadcaster(broadcaster) {
    _data = DataFactory::newDataByID(dataID);
    assert(_data != nullptr);
    if(_data == nullptr) {
        _data = DataFactory::newDataByID(DataFactory::DEFAULT_DATA);
    }

    // Reserve values are totally arbitrary here.
    _users.reserve(15);
    _operations.reserve(100);
}

Room::~Room() {
    DataFactory::releaseData(_data);
    if(_storage != nullptr) {
        delete _storage;
    }
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
// Storage
// -----------------------------------------------------------------------------

bool Room::hasStorage() const {
    return _storage != nullptr;
}

bool Room::assignStorage(StorageConfig& config) {
    if(_storage != nullptr) {
        return false;
    }
    _storage = new Storage(config, *this, *_data, _broadcaster);
    if(_storage == nullptr) {
        return false;
    }
    return true;
}


// -----------------------------------------------------------------------------
// Operations
// -----------------------------------------------------------------------------

bool Room::commitOperation(const OperationInfo& op) {
    assert(_data != nullptr);
    if(_data == nullptr) {
        return false;
    }

    bool isApplied = _data->applyExternOperation(op.buffer);
    if(!isApplied) {
        return false;
    }

    if(op.roomID != _id || !this->hasUser(op.userID)) {
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

    for(const int userID : _users) {
        if(op.userID == userID) {
            continue;
        }
        _broadcaster.sendOperationToUser(newOP, userID);
    }

    if(this->hasStorage()) {
        _storage->commitOperation(newOP);
    }

    return true;
}


// -----------------------------------------------------------------------------
// Various
// -----------------------------------------------------------------------------

int Room::getRoomID() const {
    return _id;
}

int Room::getNextExpectedRoomID() {
    return Room::idcounter + 1;
}


} // End namespace


