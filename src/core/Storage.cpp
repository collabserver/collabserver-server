#include "collabserver/core/Storage.h"

#include <cassert>

#include "collabserver/core/Broadcaster.h"
#include "collabdata/custom/CollabData.h"

namespace collab {


Storage::Storage(StorageConfig c, const Room& r, CollabData& d, Broadcaster& b)
        : _config(c), _room(&r), _data(&d), _broadcaster(&b) {
    if(_config.mode == StorageConfig::LINEAR_OPERATIONS) {
        _data->addOperationObserver(*this);
    }
}

Storage::~Storage() {
    // TODO Remove from _data observers (But this is not implemented yet)
}

void Storage::notifyOperation(const Operation& op) {
    if(_config.mode == StorageConfig::LINEAR_OPERATIONS) {
        assert(_broadcaster != nullptr);
        // TODO
        // Call broadcaster
    }
}

void Storage::commitOperation(OperationInfo& op) {
    if(_config.mode == StorageConfig::CRDT_OPERATIONS) {
        assert(_broadcaster != nullptr);
        // TODO
        //_broadcaster->sendOperation(op);
    }
}


} // End namespace


