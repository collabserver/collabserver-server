#pragma once

#include "collabdata/custom/OperationObserver.h"

#include "StorageConfig.h"

namespace collab {


class Room;
class CollabData;
class OperationInfo;
class Broadcaster;


/**
 * \brief
 * Element in charge of actual CollabData storage.
 *
 * Storage receives operations from the Room it is linked with and send them
 * to the actual distant database. This is only a proxy so that, the actual
 * database implementation is unknown here. On the other side, database
 * runs a client that receives operation and convert to apply them inside the
 * database.
 *
 *
 * \author  Constantin Masson
 * \date    July 2018
 */
class Storage : public OperationObserver {
    private:
        StorageConfig       _config;
        const Room*         _room           = nullptr;
        CollabData*         _data           = nullptr;
        Broadcaster*        _broadcaster    = nullptr;

    public:
        Storage(StorageConfig c, const Room& r, CollabData& d, Broadcaster& b);

    public:
        void notifyOperation(const Operation& op) override;
        void receiveOperation(OperationInfo& op);
};


} // End namespace


