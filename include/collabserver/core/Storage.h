#pragma once

#include "collabdata/custom/OperationObserver.h"
#include "collabdata/custom/CollabData.h"

#include "StorageConfig.h"
#include "Broadcaster.h"

namespace collab {

class Room;


/**
 * \brief
 * Element in charge of actual CollabData storage.
 *
 * This is only a kind of proxy of the actual physical storage.
 *
 * \author  Constantin Masson
 * \date    July 2018
 */
class Storage : public OperationObserver {
    private:
        StorageConfig       _config;
        const Room*         _room = nullptr;
        CollabData*         _data = nullptr;
        Broadcaster*        _broadcaster = nullptr;

    public:
        Storage(StorageConfig config, const Room& room, CollabData& data,
                Broadcaster& broadcast)
                : _config(config), _room(&room), _data(&data),
                _broadcaster(&broadcast) {
            if(_config.mode == StorageConfig::LINEAR_OPERATIONS) {
                _data->addOperationObserver(*this);
            }
        }

    public:
        // TODO ToFix
        void notifyOperation(const Operation& op) {
            if(_config.mode == StorageConfig::LINEAR_OPERATIONS) {
                // TODO
                // Call broadcaster
            }
        }

        void receiveOperation(OperationInfo& op) {
            if(_config.mode == StorageConfig::CRDT_OPERATIONS) {
                // TODO
                // Call broadcaster
            }
        }
};


} // End namespace


