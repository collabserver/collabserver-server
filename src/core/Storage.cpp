#include "collabserver/core/Storage.h"

#include "collabdata/custom/CollabData.h"

namespace collab {


Storage::Storage(StorageConfig c, const Room& r, CollabData& d, Broadcaster& b)
        : _config(c), _room(&r), _data(&d), _broadcaster(&b) {
    if(_config.mode == StorageConfig::LINEAR_OPERATIONS) {
        _data->addOperationObserver(*this);
    }
}

void Storage::notifyOperation(const Operation& op) {
    if(_config.mode == StorageConfig::LINEAR_OPERATIONS) {
        // TODO
        // Call broadcaster
    }
}

void Storage::receiveOperation(OperationInfo& op) {
    if(_config.mode == StorageConfig::CRDT_OPERATIONS) {
        // TODO
        // Call broadcaster
    }
}


} // End namespace


